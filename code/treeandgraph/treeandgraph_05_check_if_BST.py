
from treeandgraph_00_build_traverse import *

def checkBST(cr, minimal, maximal):
    if cr._val > maximal or cr._val < minimal:
        return False
    lresult, rresult = True, True
    if cr._lchild:
        lresult = checkBST(cr._lchild, minimal, cr._val)
        if cr._rchild:
            rresult = checkBST(cr._rchild, cr._val, maximal)
    if lresult and rresult:
        return True
    else:
        return False

def test():
    pro = "ABDECGF"
    ino = "DBEACGF"
    root = build_tree(pro, ino, 0, len(pro) - 1, 0, len(ino) - 1)
    preord_traverse(root)
    print checkBST(root, 'A', 'Z')

test()
