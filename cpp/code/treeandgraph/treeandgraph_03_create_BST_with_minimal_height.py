
from treeandgraph_00_build_traverse import *

def buildMST(array, start, end):
    if end - start <= 0:
        return None
    mid = start + (end - start) / 2
    print mid, array[mid]
    newRoot = TreeNode(array[mid])
    newRoot._lchild = buildMST(array, start, mid)
    newRoot._rchild = buildMST(array, mid + 1, end)
    return newRoot

def test():
    data = [1,2,3,4,5,6,7]
    root = buildMST(data, 0, len(data))
    inord_traverse(root)

test()
