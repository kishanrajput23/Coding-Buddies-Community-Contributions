import pyttsx3
print("Type 'Exit' to exit this program")
while True:
    text = input("Enter a string: ")
    if text != 'Exit' and text != 'exit':
        engine = pyttsx3.init()
        
        voices = engine.getProperty('voices')
        rate = engine.getProperty('rate')
        
        engine.setProperty('voice', voices[1].id)
        #Index 0 for male voice and 1 for female voice.
        
        engine.setProperty('rate', 150)
        #Default playback speed is 200.
        
        engine.say(text)
        engine.runAndWait()
    else:
        exit()