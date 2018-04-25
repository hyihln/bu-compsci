
#import modules
import listoperations
import random

#create function to create random list
def createRandomInts():
    low = -51
    high = 51
    randlist = []
    for i in range(random.randrange(1,high)):
        integer = random.randrange(low,high)
        randlist.append(integer)
    return(randlist)

#create function to count lowercase letters in a string
def countAll(string):
    new_string = string.lower()
    dictionary = {}
    ascii_number = 97
    while ascii_number < 123:
        counter = new_string.count(chr(ascii_number))
        if counter != 0:
            dictionary[chr(ascii_number)] = counter
        ascii_number += 1
    print(dictionary)
    return dictionary

#creates main function
def main():
    randlist = createRandomInts()
    print(randlist)
    the_sum = listoperations.computeSum(randlist)
    the_average = listoperations.computeAverage(randlist)
    min_value = listoperations.findMinValue(randlist)
    max_value = listoperations.findMaxValue(randlist)
    print([the_sum,the_average,min_value,max_value])
    string = "banana"
    countAll(string)

#calls main function
main()
