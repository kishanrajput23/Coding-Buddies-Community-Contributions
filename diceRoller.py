'''
Python GUI Dice Roller
'''
from tkinter import *
import random

def rollDice():
    dice = [1,2,3,4,5,6]
    roll = random.choice(dice)

    Text = Label(text = roll , font=("Arial" , 250), fg="brown" ,relief=SUNKEN, bg="#BBF1F1" , borderwidth=20)
    Text.place(x=280 , y=20)





root = Tk()

root.title('Dice Roller')

root.geometry('800x500')

root.config(bg='#30D5C8')


# SUNKEN, RAISED, GROOVE, and RIDGE.


rollBut = Button(text='Roll',relief=SUNKEN,bd=8,fg='brown',command=rollDice)

rollBut.place(x=370,y=390)


root.mainloop()

