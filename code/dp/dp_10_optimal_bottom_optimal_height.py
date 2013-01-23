
maxHeight = 0

def check(stack, box):
    if not stack:
        return True
    bottom = stack[0]
    if box[0] > bottom[0] and box[1] > bottom[1] and box[2] > bottom[2]:
        return True
    else:
        return False

def getHeight(stack):
    height = 0
    for s in stack:
        height += s[1]
    return height

def opt(i, boxes, stack):
    print stack
    global maxHeight
    if i == len(boxes):
        curHeight = getHeight(stack)
        if curHeight > maxHeight:
            maxHeight = curHeight
        return

    flag = True
    for box in boxes:
        if box not in stack and check(stack, box):
            flag = False
            opt(i + 1, boxes, [box] + stack)
    if flag:
        curHeight = getHeight(stack)
        if curHeight > maxHeight:
            maxHeight = curHeight

def test():
    boxes = [(4,3,4), (5,4,6), (7,8,9)]
    opt(0, boxes, [])
    print maxHeight

test()
