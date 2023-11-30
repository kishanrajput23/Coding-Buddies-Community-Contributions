import turtle

def main():
    # Create a list of numbers 
    list = [32, 23, 45, 34, 4, 90, 23, 25]
    drawHistogram(list)

    turtle.done() 

def drawHistogram(list):
    WIDTH = 400 # Width of the histogram
    HEIGHT = 300 # Height of the histogram

    # Draw a base line
    turtle.penup()
    turtle.goto(-WIDTH / 2, -HEIGHT / 2)
    turtle.pendown()
    turtle.forward(WIDTH)

    widthOfBar = WIDTH / len(list) # Width of each bar

    for i in range(len(list)):     
        height = list[i] * HEIGHT / max(list) 
        drawABar(-WIDTH / 2 + i * widthOfBar, 
            -HEIGHT / 2, widthOfBar, height)     

    turtle.hideturtle()

def drawABar(i, j, widthOfBar, height):
    turtle.penup()
    turtle.goto(i, j)
    turtle.setheading(90) # Set orientation to north
    turtle.pendown()

    # turtle.left(90) # Turn left 90 degrees
    turtle.forward(height) # Draw a vertical line
    turtle.right(90) # Turn right 90 degrees
    turtle.forward(widthOfBar) # Draw a horizontal line
    turtle.right(90) # Turn right 90 degrees
    turtle.forward(height) # Draw a vertical line

main()