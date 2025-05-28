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

class FindAPhdScraper:
    def __init__(self):
        options = webdriver.ChromeOptions()
        options.add_argument('--disable-blink-features=AutomationControlled')
        # options.add_argument('--headless=new')
        options.add_argument('--disable-blink-features=AutomationControlled')
        options.add_argument("--window-size=1080,720")
        options.add_argument("user-agent=Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.212 Safari/537.36")
        self.driver = webdriver.Chrome(
            service=Service(ChromeDriverManager().install()),
            options=options
        )
        self.baseUrl = "https://www.findaphd.com"
        self.delayRange = (3, 7)
        self.timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
        self.scriptDir = os.path.dirname(os.path.abspath(__file__))
        
        # Define file paths
        self.metadataPath = os.path.join(self.scriptDir, "search_history.csv")
        self.currentListingsPath = os.path.join(self.scriptDir, f"phd_listings_{self.timestamp}.csv")
        
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

        self.ai_skills = [
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
        ]

    def randomDelay(self):
        time.sleep(random.uniform(*self.delayRange))

    def acceptCookies(self):
        try:
            cookie_btn = WebDriverWait(self.driver, 10).until(
                EC.element_to_be_clickable((By.ID, "onetrust-accept-btn-handler"))
            )
            cookie_btn.click()
            self.randomDelay()
        except:
            pass

    def getUserInput(self):
        print("\n" + "-"*50)
        print("FindAPhd.com Scraper".center(50))
        print("-"*50 + "\n")
        keywords = input("Enter search term: ").strip()
        while True:
            try:
                numResults = int(input("How many results? (15 per page): "))
                if numResults > 0:
                    return keywords, numResults
                print("Please enter a positive number")
            except ValueError:
                print("Please enter a valid number")

    def countSkillOccurrences(self, text, skill):
        if skill == "R_programming": # Special hadnling for R_programming skill
            return len(re.findall(r'\b[Rr]\b(?!\w)', text))
        return len(re.findall(rf'\b{re.escape(skill.split()[0].lower())}\b', text))
    
    def isProgramListing(self, url):
        return '/program/' in url.lower()
    
    def processProgramListing(self, programResult):
        print(f"\nProcessing program: {programResult['Title']}")
        self.driver.get(programResult['Link'])
        self.randomDelay()
        
        try:
            WebDriverWait(self.driver, 15).until(
                EC.presence_of_element_located((By.CSS_SELECTOR, "#dept-phd__holder a.card"))
            )
            soup = BeautifulSoup(self.driver.page_source, 'html.parser')
            
            projects = []
            for card in soup.select("#dept-phd__holder a.card"):
                try:
                    if not card.get('href'):
                        continue
                        
                    projectUrl = card['href']
                    if self.isProgramListing(projectUrl):
                        continue
                        
                    projectUrl = f"{self.baseUrl}{projectUrl}" if not projectUrl.startswith('http') else projectUrl
                    title = card.select_one('span.h4.text-dark').get_text(strip=True)
                    
                    # Extract university and department from the program page
                    instDeptContainer = card.select_one('div.instDeptRow')
                    university = ""
                    department = ""
                    
                    if instDeptContainer:
                        spans = instDeptContainer.find_all('span', class_=True)
                        if len(spans) >= 2:
                            university = spans[0].get_text(strip=True)
                            department = spans[-1].get_text(strip=True)
                    
                    # Create complete entry w/program
                    project = {
                        'Title': title,
                        'Link': projectUrl,
                        'University': university,
                        'Department': department,
                        'Program Title': programResult['Title'],
                        'Program Link': programResult['Link'],
                        'Top Skills': [],
                        'Supervisor': [],
                        'Tags': [],
                        'Country': programResult.get('Country', ''),
                        'Funding': '',
                        'Full Description': '',
                        'FromProgram': True 
                    }
                    projects.append(project)
                    
                    print(f"Extracted: {title[:30]}...")
                    print(f"  University: '{university}'")
                    print(f"  Department: '{department}'")
                    
                except Exception as e:
                    print(f"Error extracting project from program: {e}")
                    continue
            
            print(f"Found {len(projects)} projects in program")
            return projects
            
        except Exception as e:
            print(f"Error processing program: {e}")
            return []
            
    def analyzePosting(self, result):
        if self.isProgramListing(result['Link']):
            # Get all program subprojects and process each
            subprojects = self.processProgramListing(result)
            analyzedProjects = []
            
            for project in subprojects:
                try:
                    analyzedProject = self.processRegularProject(project)
                    analyzedProjects.append(analyzedProject)
                    self.randomDelay()
                except Exception as e:
                    print(f"Error analyzing subproject: {e}")
                    continue
            return analyzedProjects
        else:
            # Process regular project
            try:
                return [self.processRegularProject(result)]
            except Exception as e:
                print(f"Error analyzing project: {e}")
                return []
        
    def processRegularProject(self, project):
        print(f"\nAnalyzing: {project['Link']}")
        
        # Keep program university + department
        isProgramSubproject = self.isProgramListing(project.get('Program Link', ''))
        originalUniversity = project.get('University', '')
        originalDepartment = project.get('Department', '')
        
        self.driver.get(project['Link'])
        self.randomDelay()
        
        try:
            WebDriverWait(self.driver, 15).until(
                EC.presence_of_element_located((By.CSS_SELECTOR, ".phd-sections__content, .phd-data__container"))
            )
            soup = BeautifulSoup(self.driver.page_source, 'html.parser')
            
            # Get university + department
            if not isProgramSubproject:
                department = ""
                university = ""
                providerSpan = soup.find('span', itemprop='provider')
                if providerSpan:
                    departmentTag = providerSpan.find('a', class_='phd-header__department')
                    if departmentTag:
                        department = departmentTag.get_text(strip=True)
                    universityTag = providerSpan.find('a', class_='phd-header__institution')
                    if universityTag:
                        university = universityTag.get_text(strip=True)

                project['Department'] = department
                project['University'] = university

            # Get tags, country, and description
            tags = [tag.get_text(strip=True) for tag in soup.select('div.phd-data__container a.phd-data')]
            project['Tags'] = tags
            country = tags[1] if len(tags) > 1 else ""
            project['Country'] = country

            # Get funding info
            fundingInfo = ""
            keyInfoDiv = soup.find('div', class_='key-info')
            if keyInfoDiv:
                for span in keyInfoDiv.find_all('span', class_='key-info__content'):
                    icon = span.find('i', class_=lambda x: x and 'fa-wallet' in x)
                    if icon:
                        fundingText = span.get_text(strip=True)
                        if "Self-Funded PhD Students Only" in fundingText:
                            fundingInfo = "Self-Funded"
                        else:
                            fundingInfo = fundingText
                        break

            project['Funding'] = fundingInfo

            # Get supervisor
            supervisors = []
            keyInfoDiv = soup.find('div', class_='key-info')
            if keyInfoDiv:
                for span in keyInfoDiv.find_all('span', class_='key-info__content'):
                    icon = span.find('i', class_=lambda x: x and 'fa-person-chalkboard' in x)
                    if icon:
                        supervisorLinks = span.find_all('a', class_='emailLink')
                        if supervisorLinks:
                            for link in supervisorLinks:
                                supervisors.append(link.get_text(strip=True))
                        else:
                            text = span.get_text(', ', strip=True)
                            text = text.replace('&nbsp;', ' ').replace(' , ', ', ').strip()
                            if text:
                                for name in [n.strip() for n in text.split(',')]:
                                    if name:
                                        supervisors.append(name)

            project['Supervisor'] = supervisors

            description = ' '.join([p.get_text() for p in soup.select('.phd-sections__content')]).lower()
            
            # Score skills
            skillScores = defaultdict(int)
            for skill in self.ai_skills:
                displaySkill = skill.replace("_programming", "")
                
                titleMatches = self.countSkillOccurrences(project['Title'].lower(), skill)
                skillScores[displaySkill] += titleMatches * 2
                
                tagMatches = sum(self.countSkillOccurrences(tag.lower(), skill) for tag in tags)
                skillScores[displaySkill] += tagMatches * 2
                
                descMatches = self.countSkillOccurrences(description, skill)
                skillScores[displaySkill] += descMatches
            
            topSkills = sorted([(k,v) for k,v in skillScores.items() if v > 0], 
                            key=lambda x: x[1], reverse=True)[:3]
            project['Top Skills'] = [f"{k} ({v})" for k,v in topSkills]

            # Ged description
            descriptionSection = soup.find('div', class_='phd-sections__content')
            if descriptionSection:
                for script in descriptionSection(["script", "style"]):
                    script.decompose()
                descriptionText = descriptionSection.get_text(separator=' ', strip=True)
                descriptionText = ' '.join(descriptionText.split())
                descriptionText = descriptionText.replace('&nbsp;', ' ')
                project['Full Description'] = descriptionText
            else:
                project['Full Description'] = ""
            
            return project
            
        except Exception as e:
            print(f"Error analyzing posting: {e}")
            project["Department"] = originalDepartment if isProgramSubproject else ""
            project["University"] = originalUniversity if isProgramSubproject else ""
            project["Country"] = ""
            project["Full Description"] = ""
            return project
        
        except Exception as e:
            print(f"Error analyzing posting: {e}")
            project["Department"] = ""
            project["Country"] = ""
            project["Full Description"] = ""
            return project

    def scrapeSearchResults(self, keywords, numResults):
        allResults = []
        page = 1
        resultsPerPage = 15
        
        while len(allResults) < numResults:
            if page == 1:
                searchUrl = f"{self.baseUrl}/phds/?Keywords={keywords.replace(' ', '+')}"
            else:
                searchUrl = f"{self.baseUrl}/phds/?Keywords={keywords.replace(' ', '+')}&PG={page}"
        
            print(f"\nScraping page {page}: {searchUrl}")
            self.driver.get(searchUrl)
            self.randomDelay()
        
            try:
                WebDriverWait(self.driver, 15).until(
                    EC.presence_of_element_located((By.CSS_SELECTOR, "div.phd-result, h3.phd-result__title")))
            except Exception as e:
                print(f"Error waiting for results: {e}")
                break
        
            soup = BeautifulSoup(self.driver.page_source, 'html.parser')
            listings = soup.select('div.phd-result, div.phd-result-card')
        
            if page > 1 and len(listings) < resultsPerPage:
                print(f"Only {len(listings)} results found {page} , reached end of results")
        
            for listing in listings:
                try:
                    title = listing.find('h3').get_text(strip=True)
                    relativeLink = listing.find('a')['href']
                    link = f"{self.baseUrl}{relativeLink}" if not relativeLink.startswith('http') else relativeLink
                    
                    result = {
                        'Title': title,
                        'Link': link,
                        'Top Skills': [],
                        'Supervisor': [],
                        'Tags': []
                    }
                    allResults.append(result)
                    
                    if len(allResults) >= numResults:
                        break
                        
                except Exception as e:
                    print(f"Error parsing listing: {e}")
                    continue
        
            if len(listings) < resultsPerPage or len(allResults) >= numResults:
                break
            
            page += 1
            self.randomDelay()

        # Get countries + disciplines
        countries = []
        disciplines = []
        if allResults:
            countrySelect = soup.find('select', id='CountryInput')
            if countrySelect:
                countries = [opt.text.split(' (')[0] for opt in countrySelect.find_all('option')[1:]]
        
            discSelect = soup.find('select', id='DiscInput')
            if discSelect:
                allDisc = []
                for option in discSelect.find_all('option')[1:]:
                    discText = option.text.strip()
                    if '(' in discText:
                        discName = discText.split(' (')[0]
                        discCount = int(discText.split(' (')[1].replace(')', ''))
                        allDisc.append((discName, discCount))
                allDisc.sort(key=lambda x: x[1], reverse=True)
                disciplines = allDisc[:5]

        print(f"\nCollected {len(allResults)} results from {page} pages")
        return allResults, countries, disciplines

    def saveResults(self, results, countries, disciplines, keywords):
        # Flatten results
        flatResults = []
        for item in results:
            if isinstance(item, list):
                flatResults.extend(item)
            else:
                flatResults.append(item)
        
        # Prepare CSV
        dataForCsv = []
        for project in flatResults:
            # Skip if this is actually a program
            if self.isProgramListing(project['Link']):
                continue
                
            row = {
                'Title': project['Title'],
                'Country': project.get('Country', ''),
                'University': project.get('University', ''),
                'Department': project.get('Department', ''),
                'Supervisor': ', '.join(project.get('Supervisor', [])),
                'Funding': project.get('Funding', ''),
                'Top Skills': ', '.join(project.get('Top Skills', [])),
                'Tags': ', '.join(project.get('Tags', [])),
                'Link': project['Link'],
                'Full Description': project.get('Full Description', ''),
                'Program Title': project.get('Program Title', ''),
                'Program Link': project.get('Program Link', '')
            }
            dataForCsv.append(row)
        
        # Save CSV
        df = pd.DataFrame(dataForCsv)
        csvPath = os.path.join(self.scriptDir, f"phd_listings_{self.timestamp}.csv")
        df.to_csv(csvPath, index=False)
        
        # Update metadata
        skillTotals = defaultdict(int)
        for r in flatResults:
            if not self.isProgramListing(r['Link']):
                for skillEntry in r.get('Top Skills', []):
                    skill, score = skillEntry.split(' (')
                    skillTotals[skill] += int(score.rstrip(')'))
        
        newMetadata = pd.DataFrame([{
            'Search Timestamp': self.timestamp,
            'Search Terms': keywords,
            'Available Countries': ', '.join(countries),
            'Top Disciplines': ', '.join(f"{d} ({c})" for d,c in disciplines),
            'Top Demand Skills': ', '.join(f"{k} ({v})" for k,v in sorted(
                skillTotals.items(), key=lambda x: x[1], reverse=True)[:5]),
            'Listings File': os.path.basename(csvPath)
        }])
        
        metadataDf = pd.read_csv(self.metadataPath)
        metadataDf = pd.concat([metadataDf, newMetadata], ignore_index=True)
        metadataDf.to_csv(self.metadataPath, index=False)
        
        print(f"\Saved listings to:\n{csvPath}")

    def run(self):
        try:
            keywords, numResults = self.getUserInput()
            if not keywords:
                print("No terms entered.")
                return
        
            results, countries, disciplines = self.scrapeSearchResults(keywords, numResults)
        
            if not results:
                print("\nNo results found. Try disabling headliess mode.")
                return
        
            print(f"\nFound {len(results)} postings. Analyzing...")
            
            analyzedResults = []
            for result in results:
                analyzed = self.analyzePosting(result)
                if isinstance(analyzed, list):
                    analyzedResults.extend(analyzed)
                else:
                    analyzedResults.append(analyzed)
                self.randomDelay()
        
            self.saveResults(analyzedResults, countries, disciplines, keywords)
        
            print("\n--- Summary ---")
            print(f"Timestamp: {self.timestamp}")
            print(f"Keywords: {keywords}")
            print(f"\nTop skills:")
            skill_totals = defaultdict(int)
            for r in analyzedResults:
                for skill_entry in r.get('Top Skills', []):
                    skill, score = skill_entry.split(' (')
                    skill_totals[skill] += int(score.rstrip(')'))
            for skill, total in sorted(skill_totals.items(), key=lambda x: x[1], reverse=True)[:5]:
                print(f"- {skill}: {total} total points")
            
        except Exception as e:
            print(f"\nError: {e}")
        finally:
            self.driver.quit()

    def runSearch(self, keywords, numResults):
        self.timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
        results, countries, disciplines = self.scrapeSearchResults(keywords, numResults)
    
        if not results:
            print(f"No results found for '{keywords}'")
            return
    
        print(f"Analyzing {len(results)} postings...")
        for result in results:
            result = self.analyzePosting(result)
            self.randomDelay()
    
        self.saveResults(results, countries, disciplines, keywords)

if __name__ == "__main__":
    scraper = FindAPhdScraper()
    scraper.run()