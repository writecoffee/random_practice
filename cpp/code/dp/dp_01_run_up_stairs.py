
cache = None

def run(n):
    global cache
    if n < 0:
        return 0
    if n == 0:
        return 1
    if cache[n]:
        return cache[n]
    else:
        cache[n] = run(n - 1) + run(n - 2) + run(n - 3)
        return cache[n]

def test(n=3):
    global cache
    cache = [None,] * (n + 1)
    print run(n)

test()

