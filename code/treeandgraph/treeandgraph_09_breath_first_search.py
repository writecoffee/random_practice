
def bfs(G, v, dest):
    visited = {v:True}
    depth = 0
    queue = []
    depq = []
    while queue:
    depth += 1
    for neighbor in [nb for nb in G[v] if nb not in visited]:
    	visited[neighbor] = True
    	queue += neighbor

