
maxHeight = 0
cache = {}

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

def opt(boxes, stack):
    global maxHeight

    # return content from cache
    if stack and stack[0] in cache:
        return cache[stack[0]]

    for box in boxes:
        if box not in stack and check(stack, box):
            opt(boxes, [box] + stack)
            curHeight = getHeight([box] + stack)
            if box not in cache or curHeight > cache[box]:
                cache[box] = curHeight
            if curHeight > maxHeight:
                maxHeight = curHeight

def test():
    boxes = [(4,3,4), (5,4,6), (7,8,9)]
    opt(boxes, [])
    print maxHeight
    print cache

test()
