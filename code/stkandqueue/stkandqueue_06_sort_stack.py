
def sort_stack(stk):
    asc_buf = []
    result = []
    while stk:
        value = stk.pop()
        while result and value < result[len(result) - 1]:
            asc_buf.append(result.pop())
        result.append(value)
        while asc_buf:
            result.append(asc_buf.pop())
    return result


def test():
    data = [11,1,2,7,3,4,5,9]
    result = sort_stack(data)
    print result

test()
