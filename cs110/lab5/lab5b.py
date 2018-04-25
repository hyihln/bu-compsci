

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
def setupDartboard(wn,turtle):
    wn.setworldcoordinates(-2,-2,2,2)
    drawLine(turtle)
    drawSquare(turtle)

#creates function to determine if dot in circle
def inCircle(turtle):
    return turtle.distance(0,0)
    

#creates function to get approximation of Pi
def montePi(turtle,numdarts,wn):
    dot_sz = 5
    color1 = "red"
    color2 = "black"
    wn.tracer(numdarts)
    inCircleCounter = 0
    counter = 0
    while counter < numdarts:
            print (counter)
            randx = random.random()
            randy = random.random()
            multiplier = [-1,1]
            x = (random.choice(multiplier))*randx
            y = (random.choice(multiplier))*randy
            turtle.goto(x,y)
            if inCircle(turtle) <= 1:
                turtle.dot(dot_sz,color1)
                inCircleCounter += 1
            else:
                turtle.dot(dot_sz,color2)
            counter += 1
    return (inCircleCounter/numdarts)*4


#creates function main
def main():
    print("This is a program that simulates throwing darts at a dartboard\n" \
        "in order to approximate pi: The ratio of darts in a unit circle\n"\
        "to the total number of darts in a 2X2 square should be\n"\
        "approximately  equal to pi/4")
    numdarts = int(input(
    "\nPlease input the number of darts to be thrown in the simulation:  ")) 

    wn = turtle.Screen()
    slowpoke = turtle.Turtle()
    slowpoke.speed(0)
    slowpoke.up()
    setupDartboard(wn,slowpoke)
    montePi(slowpoke,numdarts,wn)
    METHOD = "a Monte Carlo Simulation"
    print("\nThe estimation of pi from %s using %d virtual darts is %.9f" %
    (METHOD, numdarts,montePi(slowpoke, numdarts, wn)))

    wn.exitonclick()

#calls to main
main()
