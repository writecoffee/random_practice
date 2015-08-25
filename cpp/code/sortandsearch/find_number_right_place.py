
import random

def findNumberRightPlace(array, length):
    minSoFarArray = [array[length - 1]]
    for i in xrange(length - 2, -1, -1):
        if array[i] <= minSoFarArray[0]:
            minSoFarArray = [array[i]] + minSoFarArray
        else:
            minSoFarArray = [minSoFarArray[0]] + minSoFarArray
    maxSoFar = array[0]
    for i in xrange(length):
        if array[i] > maxSoFar:
            maxSoFar = array[i]
        if maxSoFar <= minSoFarArray[i]:
            print i

def test(n=10):
    array = [random.randint(0, 10) for _ in range(n)]
    print array
    findNumberRightPlace(array, len(array))
    array = sorted(array)
    print array
    findNumberRightPlace(array, len(array))

test()
