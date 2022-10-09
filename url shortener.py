import pyshorteners

link = input("Enter your url : ")
short = pyshorteners.Shortener()
x = short.tinyurl.short(link)
print("Shortened url is : "+x)
