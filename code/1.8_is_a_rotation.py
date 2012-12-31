
def isRotation(str1, str2):
    str1 = str1 + str1
    if str1.find(str2) < 0:
        return False
    else:
        return True

def test(str1="_this_is", str2="_is_this"):
    print isRotation(str1, str2)

test()
