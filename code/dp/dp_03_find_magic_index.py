
def findMagicIndex(array, start, end):
    if start < 0 or start >= end:
        return -1
    mid = start + (end - start) / 2
    print start, mid, end
    if mid == array[mid]:
        return mid
    # left search
    lresult = findMagicIndex(array, start, min(mid, array[mid]))
    if lresult >= 0:
        return lresult
    rresult = findMagicIndex(array, max(mid + 1, array[mid]), end)
    return rresult

def test():
    array = sorted([5,4,7,3,0])
    print array
    print findMagicIndex(array, 0, len(array))

test()
