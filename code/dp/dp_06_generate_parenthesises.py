
strList = []

def addParen(leftRem, rightRem, string, strIndex):
    global strList
    if leftRem < 0 or rightRem < 0:
        return
    if leftRem == 0 and rightRem == 0:
        s = string[:]
        strList.append(s)
    else:
        # add left paren, if there are any left parens remaining
        if leftRem > 0:
            string[strIndex] = '('
            addParen(leftRem - 1, rightRem, string, strIndex + 1)

        if rightRem > leftRem:
            string[strIndex] = ')'
            addParen(leftRem, rightRem - 1, string, strIndex + 1)

def generateParens(count):
    string = '*' * count * 2
    addParen(count, count, bytearray(string), 0)

def test(count=4):
    global strList
    generateParens(count)
    strList[:] = map(str, strList)
    print strList

test()

