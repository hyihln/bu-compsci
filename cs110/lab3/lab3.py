

#import modules
import turtle
import math

#creates a function to draw a triangle
def drawTriangle(turtle):
    length = 30
    for i in range(3): 
        turtle.forward(length)
        turtle.left(360.0/3)

#creates a function to draw an octagon
def drawOctagon(turtle):
    length = 30
    for i in range(8): 
        turtle.forward(length)
        turtle.left(360.0/8)

#creates function to draw a polygon
def drawPolygon(turtle, sideLength, numSides):
    for i in range(numSides): 
        turtle.forward(sideLength)
        turtle.left(360.0/numSides)

#creates function to draw a set of circle
def drawCircle(turtle,radius):
    numSides = 360
    #circle above starting position
    for i in range(numSides):
        circumference = 2*(math.pi)*radius
        sideLength = circumference/numSides
        turtle.forward(sideLength)
        turtle.left(360/numSides)
    #circle below starting position
    for i in range(numSides):
        circumference = 2*(math.pi)*radius
        sideLength = circumference/numSides
        turtle.forward(sideLength)
        turtle.right(360/numSides)
    #circle centered at starting position
    turtle.penup()
    turtle.setposition(0,radius)
    turtle.pendown()
    for i in range(numSides):
        circumference = 2*(math.pi)*radius
        sideLength = circumference/numSides
        turtle.forward(sideLength)
        turtle.right(360/numSides)

#creates a function to draw a filled circle centered at starting position
def drawFilledCircle(turtle,radius,color):
    numSides = 360
    turtle.penup()
    turtle.setposition(0,radius)
    turtle.pendown()
    turtle.color(color)
    turtle.begin_fill()
    for i in range(numSides):
        circumference = 2*(math.pi)*radius
        sideLength = circumference/numSides
        turtle.forward(sideLength)
        turtle.right(360/numSides)
    turtle.end_fill()

#creates function main
def main():
    wn = turtle.Screen()
    slowpoke = turtle.Turtle()
    drawTriangle(slowpoke)
    drawOctagon(slowpoke)
    length = 30
    sides = 10
    radius = 50
    new_radius = radius + 25
    color = "red"
    drawPolygon(slowpoke,length,sides)
    drawCircle(slowpoke, radius)
    drawFilledCircle(slowpoke,new_radius,color)
    wn.exitonclick()

#calls to function main
main()
