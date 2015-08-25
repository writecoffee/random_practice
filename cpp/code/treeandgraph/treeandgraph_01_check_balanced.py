
from treeandgraph_00_build_traverse import *

def check_balance(root):
    if not root._lchild and not root._rchild:
        return 1, True

    ldepth, lflag = check_balance(root._lchild) if root._lchild else (0, None)
    rdepth, rflag = check_balance(root._rchild) if root._rchild else (0, None)
    print ldepth, lflag, rdepth, rflag

    if lflag is False or rflag is False:
        return max(ldepth, rdepth) + 1, False

    if abs(ldepth - rdepth) > 1:
        return max(ldepth, rdepth) + 1, False
    else:
        return max(ldepth, rdepth) + 1, True

def test():
    pro = "ABDECGF"
    ino = "DBEACGF"
    root = build_tree(pro, ino, 0, len(pro) - 1, 0, len(ino) - 1)
    inord_traverse(root)
    print
    preord_traverse(root)
    print check_balance(root)

test()
