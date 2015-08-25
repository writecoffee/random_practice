
def insertAtPos(substr, i, c):
    return substr[:i] + c + substr[i:]

def computePermutation(string):
    substrings = ['']
    for c in string:
        tmp = []
        for ss in substrings:
            for i in xrange(len(ss) + 1):
                tmp.append(insertAtPos(ss, i, c))
        substrings[:] = tmp[:]
    return substrings

def test(string="abcd"):
    result = computePermutation(string)
    print result, len(result)

test()
