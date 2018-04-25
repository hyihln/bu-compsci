
import listoperations

#creates a Forecast class
class Forecast:
    def __init__(self, city, temperature, rainfall):
        self.city = city 
        self.rainfall = rainfall
        self.temperature = temperature
       
    def Fahrenheit(self):
        return "rainfall:"+str(self.rainfall)+"\ntemperature:" +str(self.temperature)

    def Celcius(self):
        self.C_temperature = (float(self.temperature) -32)*(5/9)
        return "rainfall:"+str(self.rainfall)+"\ntemperature:"+str(self.C_temperature)


#creates a function to read lines using .readline() method
def readLine_readline(afile):
    thefile = open(afile,"r")
    rain_list = []
    for line in thefile:
        theline = line.split()
        rain_list.append(theline[2])
    #insert close file
    return (rain_list)

#creates a function to read lines using .readlines()
def readLine_readlines(afile):
    thefile = open(afile,"r")
    rain_list = thefile.readlines()
    stripped_list = [i.strip() for i in rain_list] 
    rain_list = []
    for i in stripped_list:
        new_list = i.split()
        rain_list = rain_list + [new_list[2]]
    return(rain_list)

#create function to read lines using .read()        
def readLine_read(afile):
    thefile = open(afile,"r")
    rain_list = thefile.read()
    thelist = rain_list.split("\n")
    thelist.pop()
    rain_list = []
    for i in thelist:
        new_list = i.split()
        rain_list = rain_list + [new_list[2]]
    return rain_list

#creates a main function
def main():
    rain_list = [float(i) for i in readLine_readline("rainfall.txt")]
    print("minimum: ",listoperations.findMinValue(rain_list))
    print("maximum: ", listoperations.findMaxValue(rain_list))
    print("average: ", listoperations.computeAverage(rain_list))
    print("\n")
    rain_list_2 = [float(i) for i in readLine_readlines("rainfall.txt")]
    print("minimum: ",listoperations.findMinValue(rain_list_2))
    print("maximum: ", listoperations.findMaxValue(rain_list_2))
    print("average: ", listoperations.computeAverage(rain_list_2))
    print("\n")
    rain_list_3 = [float(i) for i in readLine_read("rainfall.txt")]
    print("minimum: ",listoperations.findMinValue(rain_list_3))
    print("maximum: ", listoperations.findMaxValue(rain_list_3))
    print("average: ", listoperations.computeAverage(rain_list_3))

#PART B
    city_input = input("City name?")
    degree_input = input("F or C ?")

    afile = open("rainfall.txt","r")
    dictionary = {}
    for line in afile:
        theline = line.split()
        dictionary[theline[0]] = Forecast(theline[0],theline[1],theline[2])
    
    if degree_input == "F":
        print(dictionary[city_input].Fahrenheit())
    elif degree_input == "C":
        print(dictionary[city_input].Celcius())
    else:
        print("Invalid Input")
        
#calls to main
main()
