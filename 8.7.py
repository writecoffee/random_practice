def coins(n):
    ways = [(a, b, c, d, e) 
            for a in range(1 + int(n / 50))
            for b in range(1 + int(n - 50 * a) / 25)
            for c in range(1 + int(n - 50 * a - 25 * b) / 10)
            for d in range(1 + int(n - 50 * a - 25 * b - 10 * c) / 5)
            for e in range(1 + int(n - 50 * a - 25 * b - 10 * c - 5 * d))
            if  a * 50 + b * 25 + c * 10 + d * 5 + e == n]
    return ways

result = coins(11)
print result
print len(result)
