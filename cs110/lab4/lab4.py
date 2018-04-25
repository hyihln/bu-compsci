


#import modules
import math
import turtle

#create function to set up window
def setupWindow(screen):
    color = "lightblue"
    screen.bgcolor(color)
    lower_left_x = -25
    lower_left_y = -2
    upper_right_x = 25
    upper_right_y = 2
    screen.setworldcoordinates(lower_left_x,lower_left_y,upper_right_x,upper_right_y)

#creates function to set up turtle axis
def setupTurtle(turtle):
    turtle.penup()
    turtle.goto(-25,0)
    turtle.pendown()
    turtle.goto(25,0)
    turtle.penup()
    turtle.goto(0,2)
    turtle.pendown()
    turtle.goto(0,-2)
    turtle.penup()
    turtle.goto(0,0)

#creates function to draw sine curve
def drawSineCurve(turtle):
    turtle.pendown()
    for i in range(361):
        coordx = (math.radians(i))
        coordy = (math.sin(math.radians(i)))
        turtle.goto(coordx,coordy)

#create function to draw cosine curve
def drawCosineCurve(turtle):
    turtle.penup()
    turtle.goto(0,0)
    turtle.pendown()
    for i in range(361):
        coordx = math.radians(i)
        coordy = (math.cos(math.radians(i)))
        turtle.goto(coordx,coordy)

#create function to draw log curve
def drawLogCurve(turtle):
    turtle.penup()
    turtle.goto(.1,0)
    turtle.pendown()
    i = 0.1
    while i < 361:
        coordx = i
        coordy = math.log(coordx)
        turtle.goto(coordx,coordy)
        i += 0.1

#creates main function
def main():
    wn = turtle.Screen()
    slowpoke = turtle.Turtle()
    setupWindow(wn)
    setupTurtle(slowpoke)
    drawSineCurve(slowpoke)
    drawCosineCurve(slowpoke)
    drawLogCurve(slowpoke)
    wn.exitonclick()

#calls main function
main()
