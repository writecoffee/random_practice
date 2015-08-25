
import random

cache = None

def printPath(matrix):
    output = []
    for i in range(len(matrix)):
        if matrix[i] == 0:
            output += ["D"]
        else:
            output += ["R"]
    print output

def getAllPathNonRecur(n):
    path = []
    for i in range(n):
        path += [1]
    for i in range(n):
        path += [0]

    printPath(path)
    i = 0
    while i < 2 * n - 1:
        # seek a chance to swap (Down, Right) sequence pair
        if path[i] == 1 and path[i + 1] == 0:
            (path[i], path[i + 1]) = (path[i + 1], path[i])
            printPath(path)
            i = 0
        else:
            i += 1

def getAllPath(curr_path, x, y):
    if x is 0 and y is 0:
        print curr_path
        return
    elif x < 0 or y < 0:
        return
    curr_path = [(x - 1, y)] + curr_path
    getAllPath(curr_path, x - 1, y)
    curr_path = curr_path[1:]
    curr_path = [(x, y - 1)] + curr_path
    getAllPath(curr_path, x, y - 1)

# randomization function judging valid step point
def isFree(x, y):
    if random.randint(1, 1000) % 9 > 1:
        return True
    else:
        return False

def getPath(x, y, path):
    global cache
    if (x, y) in cache:
        return cache[(x, y)]
    path.append((x, y))
    if x == 0 and y == 0:
        print path
        return True
    success = False
    # can go right
    if x >= 1 and isFree(x - 1, y):
        success = getPath(x - 1, y, path)
    # can go down
    if not success and y >= 1 and isFree(x, y - 1):
        success = getPath(x, y - 1, path)
    if not success:
        path.pop()
    else:
        cache[(x, y)] = True
    return success

def test():
    global cache
    cache = {}
    getPath(3, 3, [])

test()
getAllPath([(3, 3)], 3, 3)
getAllPathNonRecur(4)
