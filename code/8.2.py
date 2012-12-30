#curr_path = []


def print_path(matrix):
	output = []
	for i in range(len(matrix)):
		if matrix[i] == 0:
			output += ["D"]
		else:
			output += ["R"]
	print output


def get_path_non_recv(n):
	path = []
	for i in range(n):
		path += [1]
	for i in range(n):
		path += [0]

	print_path(path)
	i = 0
	while i < 2 * n - 1:
		if path[i] == 1 and path[i + 1] == 0:
			(path[i], path[i + 1]) = (path[i + 1], path[i])
			print_path(path)
			i = 0
		else:
			i += 1
	

def get_path(curr_path, x, y):
	if x is 0 and y is 0:
		print curr_path
		return
	elif x < 0 or y < 0:
		return

	curr_path = [(x - 1, y)] + curr_path
	get_path(curr_path, x - 1, y)

	curr_path = curr_path[1:]

	curr_path = [(x, y - 1)] + curr_path
	get_path(curr_path, x, y - 1)

get_path([(3, 3)], 3, 3)
get_path_non_recv(4)

