
#creates function to compute the sum
def computeSum(values):
    the_sum = 0
    for i in range(len(values)):
        the_sum += values[i]
    return (the_sum)

#creates a function to compute the average
def computeAverage(values):
    the_sum = computeSum(values)
    the_average = (the_sum)/(len(values))
    return (the_average)

#creates a function to find the minimum value
def findMinValue(values):
    minSoFar = values[0]
    for i in range(len(values)):
        if values[i] < minSoFar :
            minSoFar = values[i]
    return (minSoFar)

#creates a function to find the maximum value
def findMaxValue(values):
    maxSoFar = values[0]
    for i in range(len(values)):
        if values[i] > maxSoFar:
            maxSoFar = values[i]
    return maxSoFar

