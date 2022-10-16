def main():
    # Prompt the user to enter a hex number
    hex = input("Enter a hex number: ").strip()

    decimal = hexToDecimal(hex.upper())
    if decimal == None:
        print("Incorrect hex number")
    else:
        print("The decimal value for hex number", 
            hex, "is", decimal) 

def hexToDecimal(hex):
    decimalValue = 0
    for i in range(len(hex)):
        ch = hex[i]
        if 'A' <= ch <= 'F' or '0' <= ch <= '9':
            decimalValue = decimalValue * 16 + \
                hexCharToDecimal(ch)
        else:
            return None

    return decimalValue

def hexCharToDecimal(ch):
    if 'A' <= ch <= 'F':
        return 10 + ord(ch) - ord('A')
    else:
        return ord(ch) - ord('0')

main() # Call the main function
