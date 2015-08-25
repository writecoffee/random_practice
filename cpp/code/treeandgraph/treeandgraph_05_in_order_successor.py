
from treeandgraph_00_build_traverse import *

def getLeftMostChild(cr):
    lLeaf = cr._lchild
    while lLeaf:
        cr = lLeaf
        lLeaf = lLeaf._lchild
    return cr

def inOrderSuccessor(cr):
    if cr._rchild:
        lLeaf = getLeftMostChild(cr._rchild)
        if lLeaf:
            return lLeaf
        else:
            return cr._rchild
    elif cr._father and cr == cr._father._lchild:
        return cr._father
    elif cr._father and cr == cr._father._rchild:
        # go up until we are on left
        cr = cr._father
        while cr and cr == cr._father._rchild:
            cr = cr._father
        return cr
    else:
        return None

tcNode = None

def inord_traverse(cr, mv):
    global tcNode
    if not cr: return
    inord_traverse(cr._lchild, mv)
    if cr._val == mv:
        tcNode = cr
    print cr._val,
    inord_traverse(cr._rchild, mv)

def test():
    pro = "ABDECGF"
    ino = "DBEACGF"
    root = build_tree_2(pro, ino, 0, len(pro) - 1, 0, len(ino) - 1)
    preord_traverse(root)
    inord_traverse(root, 'D')
    print
    result = inOrderSuccessor(tcNode)
    if result:
        print result._val
    else:
        print 'root'

test()
