#function that performs * operation
def multiplyThem (num1, num2):
    return num1 * num2

#function that performs + operation
def addThem (num1, num2):
    return num1 + num2


#defines main function
def main():
    
    #initializes variable firstStr to be input value
    firstStr = input("Please enter a whole number:  ")
    
    #prints on screen the indicated strings and values
    #determines type of firstStr
    print("firstStr =", firstStr, "and is type", type(firstStr)) 
    
    #initializes variable secondStr to be input value
    secondStr = input("Please enter another whole number:  ")
    
    #prints to screen the indicated strings and values
    #determines the data type of secondStr
    print("secondStr =", secondStr, " and is type", type(secondStr))
    
    #initializes variable first
    #converts string input into type integer
    first = int(firstStr)
    
    #print to screen the indicated strings and values
    #determines the data type of first
    print("first =", first, "and is type", type(first))
    
    #initializes variable second
    #converts string input into type integer
    second = int(secondStr)
    
    #prints to screen the indicated strings and values
    #determines the data type of second
    print("second =", second, " and is type", type(second))
    
    
    #initializes variable theSum to be a value
    #calls on the addThem function
    theSum = addThem(first, second)
    
    #print to screen indicated strings and values
    print("The sum of your numbers is",theSum)

    #print to screen indicated strings and values
    print ("The sum of your numbers is", addThem(first, second))

#defines main function. overides initial
def main():
    
    #initializes variable firstStr to be input value
    firstStr = input("Please enter a whole number:  ")
    
    #prints on screen the indicated strings and values
    #determines type of firstStr
    print("firstStr =", firstStr, "and is type", type(firstStr), "\n") 
    
    #initializes variable secondStr to be input value
    secondStr = input("Please enter another whole number:  ")
    
    #prints to screen the indicated strings and values
    #determines the data type of secondStr
    print("secondStr =", secondStr, " and is type", type(secondStr),"\n")
    
    #initializes variable first
    #converts string input into type integer
    first = int(firstStr)
    
    #print to screen the indicated strings and values
    #determines the data type of first
    print("first =", first, "and is type", type(first))
    
    #initializes variable second
    #converts string input into type integer
    second = int(secondStr)
    
    #prints to screen the indicated strings and values
    #determines the data type of second
    print("second =", second, " and is type", type(second),"\n")
    
    #initializes variable theProduct to be a value
    #calls on the multiplyThem function
    theProduct = multiplyThem(first, second)
    
    #print to screen indicated strings and values
    print("The product of your numbers is",theProduct)

    #print to screen indicated strings and values
    print ("The product of your numbers is", multiplyThem(first, second))

#calls to main function
main()
