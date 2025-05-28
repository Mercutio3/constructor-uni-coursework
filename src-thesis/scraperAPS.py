from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from bs4 import BeautifulSoup
import pandas as pd
import time
import random
import os
import re
from datetime import datetime
from collections import defaultdict

class AcademicPositionsScraper:
    def __init__(self):
        options = webdriver.ChromeOptions()
        options.add_argument('--disable-blink-features=AutomationControlled')
        options.add_argument('--headless=new')
        self.driver = webdriver.Chrome(
            service=Service(ChromeDriverManager().install()),
            options=options
        )
        self.baseUrl = "https://academicpositions.com"
        self.delayRange = (3, 7)
        self.timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
        self.scriptDir = os.path.dirname(os.path.abspath(__file__))
        
        # Define file paths
        self.metadataPath = os.path.join(self.scriptDir, "scrape_history.csv")
        self.currentListingsPath = os.path.join(self.scriptDir, f"academicpositions_scrape_{self.timestamp}.csv")
        
        # Initialize metadata file if it doesn't exist
        if not os.path.exists(self.metadataPath):
            pd.DataFrame(columns=[
                'Search Timestamp', 
                'Search Terms', 
                'Available Countries',
                'Top Disciplines',
                'Top Demand Skills',
                'Detailed File'
            ]).to_csv(self.metadataPath, index=False)

        self.aiSkills = [
            # Programming Languages + Frameworks + Libraries
            "Python", "R_programming", "MATLAB", "Go", "Rust", "Julia", "C++" ,
            "SQL", "Java", "PyTorch", "TensorFlow", "JAX", "Hugging Face",
            "Scikit-learn", "Keras", "spaCy", "OpenCV", "LangChain", "NLTK",
            "NumPy", "Pandas",
            
            # Core ML/AI
            "machine learning", "deep learning", "neural network",
            "reinforcement learning", "supervised learning", "unsupervised learning",
            "few-shot learning", "zero-shot learning","generative model", "GANs",
            "transformer",

            # Data Science + Engineering
            "data analysis", "data mining", "data preprocessing", "feature engineering",
            "data pipeline", "data visualization",

            # Mathematics + Theory
            "linear algebra", "probability", "statistics", "optimization",
            "Bayesian methods", "information theory",

            # NLP + Computer Vision
            "natural language processing", "speech recognition", "text mining",
            "sentiment analysis", "computer vision", "object detection",
            "image segmentation", "multimodal learning",

            # Deployment + Production
            "MLOps", "model deployment", "distributed training", "model quantization",
            "ONNX", "AWS", "GCP", "Azure", "Docker", "Kubernetes", "Spark", "Ray",
            "CI/CD",

            # Research + Soft Skills
            "problem solving", "research", "peer review", "algorithm design",
            "critical thinking"
        ]

    def randomDelay(self):
        time.sleep(random.uniform(*self.delayRange))

    def getUserInput(self):
        print("\n" + "-"*50)
        print("AcademicPositions.com Scraper".center(50))
        print("-"*50 + "\n")
        keywords = input("Enter search term: ").strip()
        if not keywords:
            print("No input. Exiting...")
            return None, None
        
        while True:
            try:
                pages = input("Enter # of pages to scrape: ").strip()
                if not pages:
                    return keywords, -1
                pages = int(pages)
                if pages > 0:
                    return keywords, pages
                print("Please enter a positive number or press Enter for all pages")
            except ValueError:
                print("Please enter a valid number or press Enter for all pages")

    def countSkillOccurrences(self, text, skill):
        if skill == "R_programming": # Special handling for R_programming skill
            return len(re.findall(r'\b[Rr]\b(?!\w)', text))
        return len(re.findall(rf'\b{re.escape(skill.split()[0].lower())}\b', text))

    # Scrape results pages with pagination support"""
    def scrapeSearchResults(self, keywords, maxPages):
        
        baseSearchUrl = f"{self.baseUrl}/find-jobs?search={keywords.replace(' ', '+')}&positions[0]=phd&positions[1]=post-doc"
        print(f"\nSearch URL: {baseSearchUrl}")
        
        
        self.driver.get(baseSearchUrl)
        self.randomDelay()
        
        try:
            WebDriverWait(self.driver, 15).until(
                EC.presence_of_element_located((By.CSS_SELECTOR, "div.job-list-item")))
        except Exception as e:
            print(f"Error waiting for results: {e}")
            return [], [], []
        
        
        if maxPages == -1:
            try:
                pagination = self.driver.find_element(By.CSS_SELECTOR, "ul.pagination")
                pageLinks = pagination.find_elements(By.TAG_NAME, "a")
                if pageLinks:
                    lastPage = int(pageLinks[-2].text)
                else:
                    lastPage = 1
            except:
                lastPage = 1
            print(f"Found {lastPage} pages")
        else:
            lastPage = maxPages
            print(f"Scraping {lastPage} pages")
        
        results = []
        countries = set()
        disciplines = []
        
        for page in range(1, lastPage + 1):
            if page > 1: # Further pages
                pageUrl = f"{baseSearchUrl}&page={page}"
                self.driver.get(pageUrl)
                self.randomDelay()
                
                try:
                    WebDriverWait(self.driver, 10).until(
                        EC.presence_of_element_located((By.CSS_SELECTOR, "div.job-list-item")))
                except Exception as e:
                    print(f"Error waiting for page {page}: {e}")
                    continue
            
            soup = BeautifulSoup(self.driver.page_source, 'html.parser')
            
            # Get job listings
            currentPageListings = soup.select('div.job-list-item')
            if not currentPageListings:
                print(f"No listings found on page {page}")
                break
            
            for listing in currentPageListings:
                try:
                    title = listing.select_one('a.text-dark.text-decoration-none.hover-title-underline.job-link h4').get_text(strip=True)
                    link = listing.select_one('a.text-dark.text-decoration-none.hover-title-underline.job-link')['href']
                    results.append({
                        'Title': title,
                        'Top Skills': [],
                        'Tags': [],
                        'Link': link if link.startswith('http') else f"{self.baseUrl}{link}"
                    })
                except Exception as e:
                    print(f"Error parsing listing: {e}")
                    continue
            
            # Only need to collect countries and disciplines once (from first page)
            if page == 1:
                # Get countries
                locationHeading = None
                for h6 in soup.find_all('h6', class_='text-uppercase'):
                    if 'Location' in h6.get_text():
                        locationHeading = h6
                        break
                
                if locationHeading:
                    locationList = locationHeading.find_next_sibling('ul', class_='category-section')
                    if locationList:
                        for continentLi in locationList.find_all('li', recursive=False):
                            countryUl = continentLi.find('ul', class_='child')
                            if countryUl:
                                for countryLi in countryUl.find_all('li', recursive=False):
                                    countryLink = countryLi.find('a')
                                    if countryLink and 'name' in countryLink.attrs:
                                        countryName = countryLink['name'].replace('-', ' ').title()
                                        if countryName and len(countryName) > 2:
                                            countries.add(countryName)
                
                # Get top 5 disciplines
                fieldHeading = None
                for h6 in soup.find_all('h6', class_='text-uppercase'):
                    if 'Field' in h6.get_text():
                        fieldHeading = h6
                        break
                
                if fieldHeading:
                    fieldList = fieldHeading.find_next_sibling('ul', class_='category-section')
                    if fieldList:
                        allDisc = []
                        for item in fieldList.find_all('li', recursive=False):
                            try:
                                name = item.get_text(strip=True).split('(')[0].strip()
                                count = 0
                                countSpan = item.find('span', class_='count')
                                if countSpan:
                                    count = int(countSpan.get_text(strip=True).strip('()'))
                                allDisc.append((name, count))
                            except:
                                continue
                        allDisc.sort(key=lambda x: x[1], reverse=True)
                        disciplines = allDisc[:5]
            
            print(f"Page {page}/{lastPage} : found {len(results)} listings.")
            self.randomDelay()
        
        return results, sorted(countries), disciplines

    # Analyze skills in a single posting
    def analyzePosting(self, result):
        
        print(f"\nAnalyzing: {result['Link']}")
        self.driver.get(result['Link'])
        self.randomDelay()
        
        try:
            WebDriverWait(self.driver, 10).until(
                EC.presence_of_element_located((By.CSS_SELECTOR, "div#jobDetails, div#editor"))
            )
            soup = BeautifulSoup(self.driver.page_source, 'html.parser')
            
            tags = []
            publishDate = None
            employer = None
            country = None

            for row in soup.select('#jobDetails .row'):
                fieldLabel = row.select_one('.font-weight-bold')
                if fieldLabel:
                    labelText = fieldLabel.get_text(strip=True)
                    if 'Field' in labelText:
                        tagLinks = row.select('.col-auto.col-md-8 a.text-dark')
                        tags = [link.get_text(strip=True) for link in tagLinks]
                    elif 'Published' in labelText:
                        dateElement = row.select_one('.col-auto.col-md-8')
                        if dateElement:
                            publishDate = dateElement.get_text(strip=True)
                    elif 'Employer' in labelText:
                        employerElement = row.select_one('.col-auto.col-md-8')
                        if employerElement:
                            employer = employerElement.get_text(strip=True)
                    elif 'Location' in labelText:
                        locationElement = row.select_one('.col-auto.col-md-8')
                        if locationElement:
                            locationText = locationElement.get_text(strip=True)
                            if ',' in locationText:
                                country = locationText.split(',')[-1].strip()
            
            # Get full description 
            descriptionDiv = soup.find('div', {'id': 'editor'})
            if descriptionDiv:
                # Remove any script or style elements
                for script in descriptionDiv(['script', 'style']):
                    script.decompose()
                # Clean up text
                fullDescription = ' '.join(descriptionDiv.stripped_strings)
                # Replace multiple spaces/newlines with single space
                fullDescription = ' '.join(fullDescription.split())

            else:
                fullDescription = ""
            
            # Score skills
            skillScores = defaultdict(int)
            for skill in self.aiSkills:
                displaySkill = skill.replace("_programming", "")
                
                # Score title (2pts)
                titleMatches = self.countSkillOccurrences(result['Title'].lower(), skill)
                skillScores[displaySkill] += titleMatches * 2
                
                # Score tags (2pts)
                tagMatches = sum(self.countSkillOccurrences(tag.lower(), skill) for tag in tags)
                skillScores[displaySkill] += tagMatches * 2
                
                # Score description (1pt)
                descMatches = self.countSkillOccurrences(fullDescription.lower(), skill)
                skillScores[displaySkill] += descMatches
            
            # Store top-3 skills
            topSkills = sorted([(k,v) for k,v in skillScores.items() if v > 0], 
                              key=lambda x: x[1], reverse=True)[:3]
            result['Top Skills'] = [f"{k} ({v})" for k,v in topSkills]
            result['Tags'] = tags
            result['Posted On'] = publishDate
            result['Employer'] = employer
            result['Country'] = country 
            result['Full Description'] = fullDescription
            
            return result
            
        except Exception as e:
            print(f"Error analyzing posting: {e}")
            return result

    # Save data to files
    def saveResults(self, results, countries, disciplines, keywords):
        # Save current listings to timestamped CSV
        listingsDf = pd.DataFrame([{
            'Title': r['Title'],
            'Employer': r.get('Employer', ''),
            'Country': r.get('Country', ''),
            'Posted On': r.get('Posted On', ''),
            'Top Skills': ', '.join(r['Top Skills']),
            'Tags': ', '.join(r['Tags']),
            'Link': r['Link'],
            'Full Description': r.get('Full Description', '')
        } for r in results])
        listingsDf.to_csv(self.currentListingsPath, index=False)
        
        # Update metadata CSV
        skillTotals = defaultdict(int)
        for r in results:
            for skillEntry in r['Top Skills']:
                skill, score = skillEntry.split(' (')
                skillTotals[skill] += int(score.rstrip(')'))
        
        newMetadata = pd.DataFrame([{
            'Search Timestamp': self.timestamp,
            'Search Terms': keywords,
            'Available Countries': ', '.join(countries),
            'Top Disciplines': ', '.join(f"{d} ({c})" for d,c in disciplines),
            'Top Demand Skills': ', '.join(f"{k} ({v})" for k,v in sorted(
                skillTotals.items(), key=lambda x: x[1], reverse=True)[:5]),
            'Listings File': os.path.basename(self.currentListingsPath)
        }])
        
        # Add to metadata
        metadataDf = pd.read_csv(self.metadataPath)
        metadataDf = pd.concat([metadataDf, newMetadata], ignore_index=True)
        metadataDf.to_csv(self.metadataPath, index=False)
        
        print(f"\nSaved listings to:\n{self.currentListingsPath}")
        print(f"Added to log:\n{self.metadataPath}")

    def run(self):
        try:
            keywords, pages = self.getUserInput()
            if not keywords:
                return
            
            results, countries, disciplines = self.scrapeSearchResults(keywords, pages)
            
            if not results:
                print("\nNo results. Try disabling headless mode.")
                return
            
            print(f"\nFound {len(results)} postings...")
            for result in results:
                result = self.analyzePosting(result)
                self.randomDelay()
            
            self.saveResults(results, countries, disciplines, keywords)
            
            print("\n--- Scraping Summary ---")
            print(f"Timestamp: {self.timestamp}")
            print(f"Keywords: {keywords}")
            print(f"\nTop skills:")
            skillTotals = defaultdict(int)
            for r in results:
                for skillEntry in r['Top Skills']:
                    skill, score = skillEntry.split(' (')
                    skillTotals[skill] += int(score.rstrip(')'))
            for skill, total in sorted(skillTotals.items(), key=lambda x: x[1], reverse=True)[:5]:
                print(f"- {skill}: {total} total points")
            
        except Exception as e:
            print(f"\nError: {e}")
        finally:
            self.driver.quit()

if __name__ == "__main__":
    scraper = AcademicPositionsScraper()
    scraper.run()