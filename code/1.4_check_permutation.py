
def is_permutation(str1, str2):
    str1 = filter(lambda ch: ch != ' ', str1)
    str2 = filter(lambda ch: ch != ' ', str2)
    chr_cnt = [0, ] * 256
    identical_cnt = 0
    if len(str1) != len(str2):
        return False
    # count chr appearance times
    for ch in str1.lower():
        if chr_cnt[ord(ch)] == 0:
            identical_cnt += 1
        chr_cnt[ord(ch)] += 1
    # check if identical char counts
    for ch in str2.lower():
        chr_cnt[ord(ch)] -= 1
        if chr_cnt[ord(ch)] < 0:
            return False
    return True

def test():
    str1 = "dog"
    str2 = "God "
    return is_permutation(str1, str2)

print test()
