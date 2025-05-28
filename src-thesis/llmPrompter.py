import pandas as pd
import time
import requests
import json

# Load Data
df = pd.read_csv("FindAPhd_UniqueResults.csv")
df = df.reset_index(drop=True)

# Build prompt object
def buildPrompt(description):
    return f"""
        You're helping me classify PhD/Post-PhD academic job postings.
        Description of Job:
        \"\"\"
        {description}
        \"\"\"
        Answer the following in JSON format with two keys:
        1. "focus": choose one of the following options based on the main aim of the posting:
            - "developing", if the position focuses on creating new AI, models, techniques, or technologies.
            - "applying", if the position focuses on using existing AI techniques to solve domain-specific problems (e.g., using ML for biology or social sciences).
            - "both", if both of the above are true
            - "neither", if the position is unrelated to AI or only uses it slightly.
        2. "tags": a list of 3–7 short, relevant tags that summarize the topics, methods, or applications of this posting.
        Please do not respond with any explanation, reasoning, or text besides the JSON object. This is an example of how I want you to respond:
        {{
        "focus": "applying",
        "tags": ["machine learning", "NLP", "healthcare"]
        }}
        """

# Feed prompt to Mistral
def getLLMResponse(prompt, endpoint="http://localhost:11434/api/generate"):
    payload = {
        "model": "mistral",
        "prompt": prompt,
        "stream": False
    }
    try:
        r = requests.post(endpoint, json=payload)
        return r.json()["response"].strip()
    except Exception as e:
        print("Error: ", e)
        return None

# Process Descriptions
focusList = []
tagList = []
rawResponses = []
for idx, row in df.iterrows():
    print(f"Processing listing {idx + 1}/{len(df)}")
    prompt = buildPrompt(row['Full Description'])
    response = getLLMResponse(prompt)

    rawResponses.append(response)
    focus = None
    tags = None

    if response:
        try:
            data = json.loads(response)
            focus = data.get("focus")
            tags = ", ".join(data.get("tags", []))
        except json.JSONDecodeError:
            print(f"Couldn't decode JSON at {idx}: {response}")

    focusList.append(focus)
    tagList.append(tags)
    time.sleep(1)

# Save Results
df['Focus'] = focusList
df['LLM Tags'] = tagList
df['Full LLM Response'] = rawResponses
df.to_csv("FAPHD_LLM_Full.csv", index=False)