

#define the function main
def main():
    
    #allows use of the following libraries
    import turtle            
    import random

    #creates screen, sets color
    wn = turtle.Screen()     
    wn.bgcolor('lightblue')

    #creates turtles, set attributes
    lance = turtle.Turtle()   
    andy = turtle.Turtle()
    lance.color('red')
    andy.color('blue')
    lance.shape('turtle')
    andy.shape('turtle')
    
    #moves turtle to coordinates without drawing
    andy.up()              
    lance.up()
    andy.goto(-100,20)
    lance.goto(-100,-20)
   		  	
    #1 Race by moving forward a random distance once
    andy_rand_dist = random.randrange(1,100)
    lance_rand_dist = random.randrange(1,100)
    print(andy_rand_dist)
    print(lance_rand_dist)
    andy.forward(andy_rand_dist)
    lance.forward(lance_rand_dist)
    
    #2 Race by moving forward a random number of set distances
    #how many times move forward is random. distance is not
    randrange = random.randrange(1,100)
    for i in range(randrange):
        andy_fix_dist = 1
        lance_fix_dist = 1
        andy.forward(andy_fix_dist)
        lance.forward(lance_fix_dist)
    
    #3 Race by moving forward a random distance for a set interval
    #distance is random. number of times is not
    steps = 150
    for i in range(steps):
        randrange = random.randrange(1,10)
        andy.forward(randrange)
        lance.forward(randrange)
    
    #exits window on click
    wn.exitonclick()
    
    #Part B Loops
    
    #Prints we like turtles 1000 times
    for i in range(1000):
        print("We like Python's turtles!")
    
    #prints each month of the year
    for i in ('January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'):
        print("One of the months of the year is "+ i)
    
    #prints each of the numbers on a new line
    for i in (12,10,32,3,66,17,42,99,20):
        print(i)
    
    #prints each number and its square on a new line
    for i in (12,10,32,3,66,17,42,99,20):
        square = (i**2)
        print("for the number "+str(i) + ", the square is " + str(square))
    
    #creates screen and turtle
    screen = turtle.Screen()
    steady = turtle.Turtle()
    steady.shape("turtle")

    #draws triangle, square, hexagon, octagon
    length = 50
    for i in range(3): 
        steady.forward(length)
        steady.left(360.0/3)
    for i in range(4):
        steady.forward(length)
        steady.left(360.0/4)
    for i in range(6):
        steady.forward(length)
        steady.left(360.0/6)
    for i in range(8):
        steady.forward(length)
        steady.left(360.0/8)
    
    #creates another turtle
    slowpoke = turtle.Turtle()
    slowpoke.shape("turtle")

    #asks user for input about polygon
    number = int(input("Enter number of sides for polygon:"))
    side = int(input("Enter the length of the side:"))
    Color = input("Enter outline & fill color of turtle:")
    
    #draws polygon and colors it in
    slowpoke.color(Color)
    slowpoke.begin_fill()
    for i in range(number): 
        slowpoke.forward(side)
        slowpoke.left(360.0/number)
    slowpoke.end_fill()
    
    #exits screen
    screen.exitonclick()

#calls main function
main()
