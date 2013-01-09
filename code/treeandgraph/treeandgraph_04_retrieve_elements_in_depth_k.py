
from treeandgraph_00_build_traverse import *

def retrieve(root, depth):
    queue, tq = [root], []
    cur_depth = 0
    while cur_depth < depth:
        while queue:
            v = queue.pop(0)
            if v._lchild:
                tq.append(v._lchild)
            if v._rchild:
                tq.append(v._rchild)
        queue, tq = tq, queue
        cur_depth += 1
    return queue

def test():
    pre_order = "abcde"
    in_order = "cbaed"
    root = build_tree(pre_order, in_order, 0, len(pre_order) - 1, 0, len(in_order) - 1)
    nodes = retrieve(root, 2)
    for i in nodes:
        print i._val,

test()
