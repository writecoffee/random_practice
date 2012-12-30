def fibo_recur(n): 
	if n == 0:
		return 0
	elif n == 1:
		return 1
	elif n > 1:
		return fibo_recur(n - 1) + fibo_recur(n - 2)
	else:
		return -1

def fibo_iter(n):
	if n < 0: return -1
	if n == 0: return 0
	a, b = 1, 1
	for x in range(2, n):
		c = a + b
		a = b
		b = c
	return b

print fibo_recur(9)
print fibo_iter(9)
