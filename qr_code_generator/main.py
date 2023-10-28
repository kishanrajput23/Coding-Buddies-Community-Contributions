import qrcode


def generate_qrcode(url):
    qr = qrcode.QRCode(
        version=1,
        error_correction=qrcode.constants.ERROR_CORRECT_L,
        box_size=10,
        border=5,
    )

    qr.add_data(url)
    qr.make(True)
    image = qr.make_image(fill_color="black", back_color="white")
    image.save("qrcode.png")


url = input("Enter a URL to generate a QR Code: ")
generate_qrcode(url)
print(f"qrcode.png has been created for {url}.")
