import random

def zero(matrix):
    m, n = len(matrix), len(matrix[0])
    mRecorder = [0,] * m
    nRecorder = [0,] * n
    for i in range(m):
        for j in range(n):
            if matrix[i][j] == 0:
                mRecorder[i] = 1
                nRecorder[j] = 1
    for i in range(m):
        for j in range(n):
            if mRecorder[i] == 1 or nRecorder[j] == 1:
                matrix[i][j] = 0

def printMatrix(matrix, m, n):
    for i in range(m):
        for j in range(n):
            print '%2d' % matrix[i][j], 
        print '\n'

def test(m=5,n=10):
    matrix = [[0] * n for x in xrange(m)]
    for i in range(m):
        for j in range(n):
            matrix[i][j] = random.randint(0, n * m)
    printMatrix(matrix, m, n)
    zero(matrix)
    print "bomb .... \n"
    printMatrix(matrix, m, n)

test()
