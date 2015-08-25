# assuming our MSB is 8
# buckets are differentiated by the most k significant bit
# we have 2^k buckets
# worst case space complexity is O(2 ^ MSB)
# worse case performance is O(n ^ 2) 
# (assuming all elements are mapped to one bucket and then insertion sort)

from ctypes import c_uint8
import math

msb = 8
k = 4


def msbits(number, k):
    return (int)(c_uint8(number).value / (2 ** (msb - k)))

def bucket_sort(array, n):
    print n
    buckets = []
    for i in range(n):
        buckets.append([])
    for i in range(len(array)):
        buckets[msbits(array[i], k)].append(array[i])
    result = []
    for a in buckets:
        result += sorted(a)
    return result

array = [3, 9, 49, 43, 37, 29, 25, 21]
print bucket_sort(array, 2 ** k)
