
visited = {}
G = {}

def dfs(s, dest):
    global visited, G
    for neighbor in G[s]:
        if neighbor == dest:
            return True
        if neighbor not in visited:
            visited[neighbor] = True
            result = dfs(neighbor, dest)
            if result is True:
                return True
    return False

def test():
    global G
    pair = [('a', 'b'), ('a', 'c'), ('c', 'd')]
    for v, w in pair:
        if v not in G:
            G[v] = {}
        if w not in G:
            G[w] = {}
        G[v][w] = 1
        G[w][v] = 1
    print G
    print dfs('a', 'd')

test()


