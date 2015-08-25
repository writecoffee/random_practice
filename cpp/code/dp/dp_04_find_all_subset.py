
def convertIntToSet(k, array):
    subset = []
    i = 0
    while k > 0:
        if (k & 1) == 1:
            subset.append(array[i])
        k >>= 1
        i += 1
    return subset

def findAllSubset(array):
    allSubsets = []
    n = len(array)
    maxVal = 1 << n
    for i in xrange(maxVal):
        subset = convertIntToSet(i, array)
        allSubsets += [subset]
    return allSubsets

def test():
    array = "abcde"
    print findAllSubset(array)

test()
