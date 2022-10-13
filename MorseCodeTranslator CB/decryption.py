import dictionary as dict

#A function used to decrypt morse code into plain text
def decryptor(text):

    #Adding a space at the end so that it can access the last letter
    text += " "
    
    #Creating list of keys and values of dictionary
    key_list= list(dict.MORSE_CODE_DICT.keys())
    val_list= list(dict.MORSE_CODE_DICT.values())

    #To store morse code in a temp variable
    morse_code=""
    plain_text=""
    for letters in text:
        if letters != " ":
            morse_code +=letters
            space_found=0
        else:
            space_found += 1
            if space_found==2:
                plain_text += " "
            else:
            
                #Accessing the index of the value i.e, morsecode and then from that index finding the key at that index
                plain_text= plain_text + key_list[val_list.index(morse_code)]
                        
                #Again making morse_code empty so that it can store next morse in it
                morse_code= ""    
    print("The plain text is: ",plain_text)
    return(plain_text)
    
    