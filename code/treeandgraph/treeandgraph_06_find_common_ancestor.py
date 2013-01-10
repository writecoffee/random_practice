
from treeandgraph_00_build_traverse import *

def cover(root, node1, node2):
    count = 0
    if root is None:
        return count
    if root == node1 or root == node2:
        count += 1
    count += cover(root._lchild, node1, node2)
    if count == 2:
        return count
    else:
        count += cover(root._rchild, node1, node2)
        return count

def findCommon(root, node1, node2):
    count = cover(root._lchild, node1, node2)
    if count == 2:
        if root == node1 or root == node2:
            return root
        return findCommon(root._lchild, node1, node2)
    if count == 1:
        if root == node1 or root == node2:
            return root
        count += cover(root._rchild, node1, node2)
        if count == 2:
            return root
        elif count == 1:
            return None

val1, val2 = 'D', 'C'
node1, node2 =  None, None

def preord_traverse(cr):
    global val1, val2, node1, node2
    if not cr: return
    if cr._val == val1 or cr._val == val2:
        if not node1:
            node1 = cr
        elif not node2:
            node2 = cr
    print cr._val,
    preord_traverse(cr._lchild)
    preord_traverse(cr._rchild)

def test():
    pre_order = "ABDECG"
    in_order = "DBEACB"
    root = build_tree(pre_order, in_order, 0, len(pre_order) - 1, 0, len(in_order) - 1)
    preord_traverse(root)
    print
    print node1._val, node2._val
    print findCommon(root, node1, node2)._val


test()
