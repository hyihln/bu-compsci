
#import module
import turtle

#creates function which keeps count, graph, and prints max count
def seq3np1(turtle):
    maxSoFar = 0
    start = 1
    end = 51
    for i in range(start,end):
        n = i
        count = 0
        while n != 1:
            count += 1
            if n % 2 == 0:
                n = n//2
            else:
                n = (n * 3) + 1
        #prints count
        print(i,"\t",count)
        #creates graph
        turtle.goto(i,count)
        #keeps track of max count
        result = count
        if result > maxSoFar:
            maxSoFar = result
    print("maxSoFar =",maxSoFar)

#creates function called main
def main():
    slowpoke = turtle.Turtle()
    wn = turtle.Screen()
    seq3np1(slowpoke)
    wn.exitonclick()

#calls main
main()


