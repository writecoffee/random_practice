
class TreeNode:
    _lchild, _rchild = None, None
    _val = None
    _father = None
    def __init__(self, val):
        self._val = val
    def setlchild(self, lchild):
        self._lchild = lchild
    def setrchild(self, rchild):
        self._rchild = rchild
    def setfather(self, father):
        self._father = father

class TreeNodeWithFather(TreeNode):
    _father = None
    def __init__(self, val):
        TreeNode.__init__(self, val)
    def setfather(self, father):
        self._father = father

def inord_traverse(cr):
    if not cr: return
    inord_traverse(cr._lchild)
    print cr._val,
    inord_traverse(cr._rchild)

def preord_traverse(cr):
    if not cr: return
    print cr._val,
    preord_traverse(cr._lchild)
    preord_traverse(cr._rchild)

def build_tree(pre_order, in_order, pl, pr, il, ir):
    nodeCnt = pr - pl + 1
    if nodeCnt <= 0: return None

    currRoot, nodeCnt = TreeNode(pre_order[pl]), pr - pl + 1
    if nodeCnt == 1:
        return currRoot

    # get root position in 'in_order' array
    ipos = il
    while in_order[ipos] != currRoot._val:
        ipos += 1

    # (L)ROOT(R)
    # ROOT(L)(R)
    currRoot.setlchild(build_tree(pre_order, in_order, \
        pl + 1, pl + ipos - il, il, ipos - 1))
    currRoot.setrchild(build_tree(pre_order, in_order, \
        pl + ipos - il + 1, pr, ipos + 1, ir))

    return currRoot

def build_tree_2(pre_order, in_order, pl, pr, il, ir):
    nodeCnt = pr - pl + 1
    if nodeCnt <= 0: return None

    currRoot, nodeCnt = TreeNode(pre_order[pl]), pr - pl + 1
    if nodeCnt == 1:
        return currRoot

    # get root position in 'in_order' array
    ipos = il
    while in_order[ipos] != currRoot._val:
        ipos += 1

    # (L)ROOT(R)
    # ROOT(L)(R)
    lchild = (build_tree_2(pre_order, in_order, pl + 1, pl + ipos - il, il, ipos - 1))
    if lchild:
        currRoot.setlchild(lchild)
        lchild.setfather(currRoot)

    rchild = (build_tree_2(pre_order, in_order, pl + ipos - il + 1, pr, ipos + 1, ir))
    if rchild:
        currRoot.setrchild(rchild)
        rchild.setfather(currRoot)

    return currRoot
