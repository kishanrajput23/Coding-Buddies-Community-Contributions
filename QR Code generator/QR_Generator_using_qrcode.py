 # importing the qrcode library  
    import qrcode  
    
    data = input("Enter the data")
    # generating a QR code 
    qr_img = qrcode.make(data)
    # saving the image file  
    qr_img.save("my_QR.jpg")
