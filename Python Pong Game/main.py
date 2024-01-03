import winsound
import turtle

# Screen
screen = turtle.Screen()
screen.title("CLASSIC PONG GAME")
screen.bgcolor("black")
screen.setup(width=800, height=600)
screen.tracer(0)

# Left paddle
paddle_left = turtle.Turtle()
paddle_left.speed(0)
paddle_left.shape("square")
paddle_left.color("white")
paddle_left.shapesize(stretch_wid=5, stretch_len=1)
paddle_left.penup()
paddle_left.goto(-350, 0)

# Right paddle
paddle_right = turtle.Turtle()
paddle_right.speed(0)
paddle_right.shape("square")
paddle_right.color("white")
paddle_right.shapesize(stretch_wid=5, stretch_len=1)
paddle_right.penup()
paddle_right.goto(350, 0)

# Ball
ball = turtle.Turtle()
ball.speed(0)
ball.shape("circle")
ball.color("white")
ball.penup()
ball.goto(0, 0)
ball.dx = .3
ball.dy = .3

# Score
score_board = turtle.Turtle()
score_board.speed(0)
score_board.color("white")
score_board.penup()
score_board.hideturtle()
score_board.goto(0, 260)
score_board.write("Player A: 0  Player B: 0", align="center", font=("Courier", 20, "bold"))

# Score
score_left = 0
score_right = 0

# Functions to move paddles

def paddle_left_up():
    y = paddle_left.ycor()
    y += 20
    paddle_left.sety(y)

def paddle_left_down():
    y = paddle_left.ycor()
    y -= 20
    paddle_left.sety(y)

def paddle_right_up():
    y = paddle_right.ycor()
    y += 20
    paddle_right.sety(y)

def paddle_right_down():
    y = paddle_right.ycor()
    y -= 20
    paddle_right.sety(y)

# Keyboard binding
screen.listen()
screen.onkeypress(paddle_left_up, "w")    # Press w to move the left paddle up
screen.onkeypress(paddle_left_down, "z")  # Press z to move the left paddle down
screen.onkeypress(paddle_right_up, "i")   # Press i to move the right paddle up
screen.onkeypress(paddle_right_down, "m") # Press m to move the right paddle down

# Main game loop
while True:
    screen.update()

    # Moving the ball
    ball.setx(ball.xcor() + ball.dx)
    ball.sety(ball.ycor() + ball.dy)

    # Border for the ball

    if ball.ycor() > 290:   # Top border
        ball.sety(290)
        ball.dy *= -1

    if ball.ycor() < -290:  # Bottom border
        ball.sety(-290)
        ball.dy *= -1

    if ball.xcor() > 390:   # Right border
        ball.goto(0, 0)
        ball.dx *= -1
        score_left += 1     # Left score increment
        score_board.clear()
        score_board.write("Player A: {}  Player B: {}".format(score_left, score_right), align="center", font=("Courier", 20, "bold"))

    if ball.xcor() < -390:  # Left border
        ball.goto(0, 0)
        ball.dx *= -1
        score_right += 1    # Right score increment
        score_board.clear()
        score_board.write("Player A: {}  Player B: {}".format(score_left, score_right), align="center", font=("Courier", 20, "bold"))

    # Ball hits on the paddles
    if (340 < ball.xcor() < 341) and (paddle_right.ycor() + 40 > ball.ycor() > paddle_right.ycor() - 40):   # When hitting on the right paddle
        ball.setx(340)
        ball.dx *= -1   # Bounce back to 0,0
        # winsound.PlaySound("jump.wav&", winsound.SND_ASYNC)

    if (-340 > ball.xcor() < -341) and (paddle_left.ycor() + 40 > ball.ycor() > paddle_left.ycor() - 40):   # When hitting on the left paddle
        ball.setx(-340)
        ball.dx *= -1   # Bounce back to 0,
        # winsound.PlaySound("jump.wav&", winsound.SND_ASYNC)

    if score_left == 3:
        winner = turtle.Turtle()
        winner.speed(0)
        winner.color("white")
        winner.penup()
        winner.hideturtle()
        winner.goto(0, 0)
        paddle_left.hideturtle()
        paddle_right.hideturtle()
        ball.hideturtle()
        winner.write("** PLAYER A WON THE GAME **", align="center", font=("Courier", 30, "bold"))

    if score_right == 3:
        winner = turtle.Turtle()
        winner.speed(0)
        winner.color("white")
        winner.penup()
        winner.hideturtle()
        winner.goto(0, 0)
        paddle_left.hideturtle()
        paddle_right.hideturtle()
        ball.hideturtle()
        winner.write("** PLAYER B WON THE GAME **", align="center", font=("Courier", 30, "bold"))