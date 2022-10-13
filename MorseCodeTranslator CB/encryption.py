import dictionary as dict

# Function used to encrypt plain text into morse code
def encryptor(text):
    encrypted_text= ""
    for letter in text:
        if letter != " ":

            #Accessing the values of letters entered and seperating each by a space and storing into a variable
            encrypted_text= encrypted_text + dict.MORSE_CODE_DICT.get(letter) + " "
        else:
            #Providing double space if it encounters a space within letters or words
            encrypted_text += " "
    print("The morse code is : ",encrypted_text)
    return(encrypted_text)
    