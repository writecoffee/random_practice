def eliminate_dup(string):
    if len(string) <= 1:
        return
    len_of_uniq = 1
    for i in range(len_of_uniq, len(string)):
        mj = len_of_uniq
        # skip over duplicate chr
        for j in range(len_of_uniq):
            if string[j] == string[i]:
                mj = j
                break
        # no duplicate found in str[0:len_of_uniq], cover the end char with 
        # the str[i], where i denotes the beginning of the uncertain sub-array,
        # namely str[len_of_uniq:]
        if mj == len_of_uniq:
            string[mj] = string[i]
            len_of_uniq += 1
    string[:] = string[:len_of_uniq]
    return string

def test(string=bytearray("banana")):
    return eliminate_dup(string)

print test()
print test(bytearray("ababab"))
print test(bytearray("aaabbb"))
