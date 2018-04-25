

import turtle
import math
import random

#create function to draw x y axis
def drawLine(turtle):
    turtle.penup()
    turtle.goto(-2,0)
    turtle.pendown()
    turtle.goto(2,0)
    turtle.penup()
    turtle.goto(0,2)
    turtle.pendown()
    turtle.goto(0,-2)
    turtle.penup()

#create function to draw square
def drawSquare(turtle):
    turtle.goto(-1,-1)
    turtle.pendown()
    turtle.setheading(0)
    for i in range(4):
        turtle.forward(2)
        turtle.left(90)
    turtle.penup()

#creates function to set up dartboard
def setupDartboard(turtle,wn):
    wn.setworldcoordinates(-2,-2,2,2)
    drawLine(turtle)
    drawSquare(turtle)

#creates function  to throw "darts"
def throwDart(turtle,numdarts):
    dot_size = 5
    color = "black"
    for i in range(numdarts):
        randx = random.random()
        randy = random.random()
        multiplier = [-1,1]
        x = (random.choice(multiplier))*randx
        y = (random.choice(multiplier))*randy
        turtle.goto(x,y)
        turtle.dot(dot_size,color)

#creates function main
def main():
    wn = turtle.Screen()
    slowpoke = turtle.Turtle()
    slowpoke.up()
    numdarts = 10
    setupDartboard(slowpoke,wn)
    throwDart(slowpoke,numdarts)

    wn.exitonclick()

#calls to main
main()
