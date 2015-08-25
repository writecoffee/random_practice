
from treeandgraph_00_build_traverse import *

path_found = []

def findSumPath(path_sum, path, cr, k):
    global path_found
    if not cr:
        return
    for i in xrange(len(path)):
        path_sum[i] += int(cr._val)
        if path_sum[i] == k:
            path_found.append(path[i:] + [cr._val])
            print path_found[-1:]
    path_sum.append(int(cr._val))
    path.append(cr._val)
    findSumPath(path_sum, path, cr._lchild, k)
    findSumPath(path_sum, path, cr._rchild, k)
    path_sum.pop()
    path.pop()

def test():
    pro = "421356"
    ino = "123456"
    root = build_tree(pro, ino, 0, len(pro) - 1, 0, len(ino) - 1)
    inord_traverse(root)
    print
    preord_traverse(root)
    print
    findSumPath([], [], root, 7)

test()
