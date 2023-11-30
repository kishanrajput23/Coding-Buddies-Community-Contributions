from tkinter import * # Import tkinter
from Graph import Graph

def add(event):
    circles.append([event.x, event.y])
    repaint()

def distance(circle1, circle2):
    return ((circle1[0] - circle2[0]) ** 2 
            + (circle1[1] - circle2[1]) ** 2) ** 0.5

def repaint():
    canvas.delete("point")
    
    if len(circles) == 0: return # Nothing to paint

    # Build the edges
    edges = []
    for i in range(len(circles)):
        for j in range(i + 1, len(circles)):
            if distance(circles[i], circles[j]) <= 2 * radius:
                edges.append([i, j])
                edges.append([j, i])

    graph = Graph(circles, edges)
    tree = graph.dfs(0)
    isAllCirclesConnected = \
        len(circles) == tree.getNumberOfVerticesFound()

    for [x, y] in circles:
        if isAllCirclesConnected: # All circles are connected
            canvas.create_oval(x - radius, y - radius, x + radius, 
                y + radius, fill = "red", tags = "point")
        else:
            canvas.create_oval(x - radius, y - radius, x + radius, 
                y + radius, tags = "point")            

window = Tk() # Create a window
window.title("ConnectedCircles") # Set title

width = 250
height = 200
radius = 15
canvas = Canvas(window, bg = "white", width = width, height = height)
canvas.pack()

# Create a 2-D list for storing circles
circles = []

canvas.bind("<Button-1>", add)

window.mainloop() # Create an event loop