import turtle

def displayMousePoint(x, y):
    turtle.write("Mouse click at (" + str(x) + ", " +
        str(y) + ")")

def displayCircle(x, y):
    turtle.circle(50)

def main():
    # Bind handlers with the mouse-click event
    turtle.onclick(displayMousePoint)
    turtle.onclick(displayCircle, add = True)
 
    turtle.done() 

main()