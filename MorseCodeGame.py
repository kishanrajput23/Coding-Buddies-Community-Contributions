import pyperclip as pc

MORSE_CODE_DICT = { 'A':'.-', 'B':'-...',
                    'C':'-.-.', 'D':'-..', 'E':'.',
                    'F':'..-.', 'G':'--.', 'H':'....',
                    'I':'..', 'J':'.---', 'K':'-.-',
                    'L':'.-..', 'M':'--', 'N':'-.',
                    'O':'---', 'P':'.--.', 'Q':'--.-',
                    'R':'.-.', 'S':'...', 'T':'-',
                    'U':'..-', 'V':'...-', 'W':'.--',
                    'X':'-..-', 'Y':'-.--', 'Z':'--..',
                    '1':'.----', '2':'..---', '3':'...--',
                    '4':'....-', '5':'.....', '6':'-....',
                    '7':'--...', '8':'---..', '9':'----.',
                    '0':'-----', ', ':'--..--', '.':'.-.-.-',
                    '?':'..--..', '/':'-..-.', '-':'-....-',
                    '(':'-.--.', ')':'-.--.-'}
#morse code provided in dictionary. Dictionary is a non-primitive data type in python

MORSE_INVERTED = {value: key for key, value in MORSE_CODE_DICT.items()}
MORSE_INVERTED[""] = " "

# function for encryption
# input in text
def encrypt(text):
    morse_code = ""
    for letter in text:
        if letter != " ":
            morse_code = morse_code + MORSE_CODE_DICT[letter]+" "
        else:
            morse_code += " "

    # copy excrypted text to clipboard
    pc.copy(morse_code)
    return morse_code

  # function for decryption
  # output in morse code
def decrypt(morse_code):
    text = ""
    morse_text=""
    morse_list = []
    morse_code+= " "

    for morse in morse_code:
        if morse != " ":
            morse_text += morse
        else:
            morse_list.append(morse_text)
            morse_text = ""
    for item in morse_list:
        text += MORSE_INVERTED[item]

    # copy decrypted text to clipboard
    pc.copy(text.title())
    return text.title()



def main():
    print()
    message = input("Enter your message: ").upper()
    print()
    while(true)
    {
      e_or_d = input("Encryption(e) or decreption(d): ").lower()
      print()
      if e_or_d == "e":
        print(f"Here is the Morse Code: {encrypt(message)}\n")
        break
      elif e_or_d == "d":
        print(f"Here is the plain text: {decrypt(message)}\n")
        break
      else:
        print("Invalid Input\n")
    }
    main()

if name == "main":
    main()
    while True:
        run_again = input("Do you want to run program again. Press any to run again (q to quit): ")
        run_again = run_again.lower()
        run_again = run_again.strip()
        print()
        if run_again == "q":
            print("Thank you for using me.\n")
            break
        else:
            main()
