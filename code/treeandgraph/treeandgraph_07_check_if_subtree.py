
from treeandgraph_00_build_traverse import *

def isSubTree(t1_cr, t2_cr):
    if not t1_cr and not t2_cr:
        return True
    if (t1_cr and not t2_cr) or (t2_cr and not t1_cr):
        return False
    if t1_cr._val == t2_cr._val:
        if isSubTree(t1_cr._lchild, t2_cr._lchild):
            if isSubTree(t1_cr._rchild, t2_cr._rchild):
                return True
        return False
    else:
        if not isSubTree(t1_cr._lchild, t2_cr):
            return isSubTree(t1_cr._lchild, t2_cr)
        else:
            return True

def test():
    pro, pro2 = "ABDECGF", "BDE"
    ino, ino2 = "DBEACGF", "DBE"
    root = build_tree(pro, ino, 0, len(pro) - 1, 0, len(ino) - 1)
    root2 = build_tree(pro2, ino2, 0, len(pro2) - 1, 0, len(ino2) - 1)

    inord_traverse(root)
    print
    preord_traverse(root)
    print

    inord_traverse(root2)
    print
    preord_traverse(root2)
    print

    print isSubTree(root, root2)

test()
