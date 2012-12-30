def replace(string):
    sp_cnt = 0
    for ch in string:
        if ch == ord(' '):
            sp_cnt += 1
    newlen = len(string) + sp_cnt * 2
    newstr = bytearray('0') * newlen
    print newstr
    rj = newlen - 1
    for i in reversed(range(len(string))):
        if string[i] == ord(' '):
            newstr[rj] = '0'
            newstr[rj - 1] = '2'
            newstr[rj - 2] = '%'
            rj -= 3
        else:
            newstr[rj] = string[i]
            rj -= 1
    return newstr


def test(string=bytearray("this is a  test    ")):
    return replace(string)

print test()
