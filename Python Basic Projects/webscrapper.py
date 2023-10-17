import requests
from bs4 import BeautifulSoup

url = 'https://example.com'
response = requests.get(url)
soup = BeautifulSoup(response.text, 'html.parser')

# Extract and print all the links on the webpage
links = soup.find_all('a')
for link in links:
    print(link.get('href'))
