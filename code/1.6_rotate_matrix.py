import random

def rotate(matrix, n):
    for i in range(n / 2):
        for j in range(i, n - i - 1):
            tmp = matrix[i][j]
            matrix[i][j] = matrix[n - 1 - j][i]
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j]
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]
            matrix[j][n - 1 - i] = tmp

def printMatrix(matrix, n):
    for i in range(n):
        for j in range(n):
            print '%2d' % matrix[i][j], 
        print '\n'

def test(n=10):
    matrix = [[0] * n for x in xrange(n)]
    for i in range(n):
        for j in range(n):
            matrix[i][j] = random.randint(1, n)
    printMatrix(matrix, n)
    rotate(matrix, n)
    print "rotate ... \n"
    printMatrix(matrix, n)


test()
