#imports modules
import turtle

#creates function to validate angle
def validation(angle):
    if angle < 0 or angle > 360:
        print("invalid input")
        return False
    else:
        print("valid")

#creates function to draw system
def drawLSystem(turtle,instructions,distance,angle):
    for cmd in instructions:
        if (cmd == "F"):
            turtle.forward(distance)
        elif(cmd == "+"):
            turtle.right(angle)
        elif(cmd == "-"):
            turtle.left(angle)

#creates function to define the rules
def rule(ch,dictionary):
    new_chr = ""
    if (dictionary.get(ch) != None):
        new_chr = dictionary[ch]
    else:
        new_chr = ch
    return new_chr

#creates function to keep track and apply the rules
def applyRules(statement,dictionary):
    accum = ""
    for c in statement:
        accum += rule(c,dictionary)
    return accum

#creates a function to create dictionary
def readFile(afile):
    Lfile = open(afile,"r")
    dictionary = {}
    dictionary["angle"] = int(Lfile.readline())
    dictionary["iteration"] = int(Lfile.readline())
    dictionary["axiom"] = Lfile.readline()
    for line in Lfile:
        Llist = line.split(":")
        dictionary[Llist[0].strip()] = Llist[1].strip()
    print (dictionary)
    Lfile.close()
    return dictionary

#create a function to access other functions    
def prep(afile,turtle):
    dictionary = readFile(afile)
    validation(int(dictionary.get("angle")))
    accum(dictionary,turtle)    

#creates function to accumulate iteration application of rules
def accum(dictionary,turtle):
    accum = dictionary.get("axiom")
    for i in range(int(dictionary.get("iteration"))):
        accum = applyRules(accum,dictionary)
    drawLSystem(turtle,accum,7,int(dictionary.get("angle")))

#creates function to define main function
def main():
    slowpoke = turtle.Turtle()
    wn = turtle.Screen()
    tracer_value = 3
    wn.tracer(tracer_value)
    slowpoke.color("blue")
    #hilbertcurve(slowpoke)
    prep("/u0/users/7/hlin65/Downloads/hilbertcurve.txt",slowpoke)
    slowpoke.color("green")
    #dragoncurve(slowpoke)
    prep("/u0/users/7/hlin65/Downloads/dragoncurve.txt",slowpoke)
    slowpoke.color("red")
    #arrowheadcurve(slowpoke)
    prep("/u0/users/7/hlin65/Downloads/arrowheadcurve.txt",slowpoke)
    slowpoke.color("purple")
    #peanogospercurve(slowpoke)
    prep("/u0/users/7/hlin65/Downloads/peanogospercurve.txt",slowpoke)
    slowpoke.color("orange")
    #sierpinskitrianglecurve(slowpoke)
    prep("/u0/users/7/hlin65/Downloads/sierpinskitrianglecurve.txt",slowpoke)
    wn.exitonclick()

#calls to main function
main()
