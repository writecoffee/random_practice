
stk1 = [2,1]
stk2 = []
stk3 = []
stacks = [stk1, stk2, stk3]

def move(offset, first, transient, third):
    if offset <= 0: return
    move(offset - 1, first, third, transient)
    stacks[third].append(stacks[first].pop())
    move(offset - 1, transient, first, third)

def test():
    move(len(stk1), 0, 1, 2)
    print stk3

test()
