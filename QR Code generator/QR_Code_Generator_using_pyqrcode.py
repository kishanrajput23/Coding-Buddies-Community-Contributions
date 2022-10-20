# importing required modules
import pyqrcode
import png
from pyqrcode import QRCode

# taking input from user 
data = input("Enter the Data: ")

# Generating QR code
qr = pyqrcode.create(data)

# Create and save the png file naming "myqr.png" with proper scaling
qr.png('myqr.png', scale=6)
