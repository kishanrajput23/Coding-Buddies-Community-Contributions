from tkinter import * # Import tkinter

window = Tk() # Create a window
window.title("Control Circle Demo") # Set a title

def increaseCircle(event):
    canvas.delete("oval")
    global radius
    if radius < 100:
        radius += 2
    canvas.create_oval(100 - radius, 100 - radius, 
                       100 + radius, 100 + radius, tags = "oval")
    
def decreaseCircle(event):
    canvas.delete("oval")
    global radius
    if radius > 2:
        radius -= 2
    canvas.create_oval(100 - radius, 100 - radius, 
                       100 + radius, 100 + radius, tags = "oval")

canvas = Canvas(window, bg = "white", width = 200, height = 200)
canvas.pack()
radius = 50
canvas.create_oval(100 - radius, 100 - radius, 
                   100 + radius, 100 + radius, tags = "oval")

# Bind canvas with mouse events
canvas.bind("<Button-1>", increaseCircle)
canvas.bind("<Button-3>", decreaseCircle)

window.mainloop() # Create an event loop