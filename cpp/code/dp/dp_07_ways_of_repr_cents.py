
def nxtDenomin(x):
    return {25: 10, 10: 5, 5: 1}.get(x, 0)

def findCoin(remaining, denomin):
    nd = nxtDenomin(denomin)
    if nd == 0:
        return 1
    ways = 0
    for i in xrange(0, remaining + 1, denomin):
        ways += findCoin(remaining - i, nd)
    return ways

def findCoinIter(n):
    ways = [(a, b, c, d, e)
            for a in xrange(0, 1 + int(n), 50)
            for b in xrange(0, 1 + int(n - a), 25)
            for c in xrange(0, 1 + int(n - a - b), 10)
            for d in xrange(0, 1 + int(n - a - b - c), 5)
            for e in xrange(int(n - a - b - c - d), 0, -1)
            if  a + b + c + d + e == n]
    return ways

print findCoinIter(11)
print findCoin(11, 10)
