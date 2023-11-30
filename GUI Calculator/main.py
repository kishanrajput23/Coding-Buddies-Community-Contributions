from tkinter import *

root = Tk()
root.title("Python Calculator")
root.geometry("430x500")
expression = ""
def setexpression(num):
    global expression
    expression = expression + str(num)
    value.set(expression)
def calculator():
    try:
        global expression
        answer = str(eval(expression))
        value.set(answer)
    except:
        value.set("Enter correct expression")
        expression = ""
def clear():
    global expression
    expression = ""
    value.set(expression)
large_font = ('Verdana', 18)
small_font = ('Verdana', 10)
value = StringVar(value="Enter expression")
Entry(root, textvariable=value, font=large_font).grid(row=0, 
    column=0, columnspan=4, ipadx=70)

Button(root, text="+", fg="red", command=lambda: 
    setexpression("+"), height=4,width=8).grid(row=1,column=3)
Button(root, text="-", fg="red", command=lambda:
    setexpression("-"), height=4, width=8).grid(row=2, column=3, pady=3)
Button(root, text="X", fg="red", command=lambda: 
    setexpression("*"), height=4, width=8).grid(row=3, column=3)
Button(root, text="/", fg="red", command=lambda: 
    setexpression("/"), height=4, width=8).grid(row=4, column=3)
Button(root, text="1", fg="red", command=lambda: 
    setexpression("1"), height=4, width=8).grid(row=1, column=0)
Button(root, text="2", fg="red", command=lambda: 
    setexpression("2"), height=4, width=8).grid(row=1, column=1)
Button(root, text="3", fg="red", command=lambda: 
    setexpression("3"), height=4, width=8).grid(row=1, column=2)
Button(root, text="4", fg="red", command=lambda: 
    setexpression("4"), height=4, width=8).grid(row=2, column=0)
Button(root, text="3", fg="red", command=lambda: 
    setexpression("3"), height=4, width=8).grid(row=2, column=1)
Button(root, text="6", fg="red", command=lambda: 
    setexpression("6"), height=4, width=8).grid(row=2, column=2)
Button(root, text="7", fg="red", command=lambda: 
    setexpression("7"), height=4, width=8).grid(row=3, column=0)
Button(root, text="8", fg="red", command=lambda: 
    setexpression("8"), height=4, width=8).grid(row=3, column=1)
Button(root, text="9", fg="red", command=lambda: 
    setexpression("9"), height=4, width=8).grid(row=3, column=2)
Button(root, text="0", fg="red", command=lambda: 
    setexpression("0"), height=4, width=8).grid(row=4, column=1)
Button(root, text=".", fg="red", command=lambda: 
    setexpression("."), height=4, width=8).grid(row=4, column=2)

Button(root, text="=", fg="red", command=calculator, height=4,
width=8).grid(row=4, column=3, pady=10)
Button(root, text="Clear", fg="red", command=clear, height=4, 
    width=8).grid(row=4, column=0, pady=10)

root.mainloop()