
from linkedlist_00_append_delete import *

def seperate_by_k(ll, k):
    smaller_head, smaller_tail = None, None
    larger_head, larger_tail = None, None
    median_head, median_tail = None, None
    curr = ll.head
    while curr != ll.end:
        if curr.data < k:
            if not smaller_head:
                smaller_head, smaller_tail = curr, curr
            else:
                smaller_tail.updateNext(curr)
                smaller_tail = curr
        elif curr.data > k:
            if not larger_head:
                larger_head, larger_tail = curr, curr
            else:
                larger_tail.updateNext(curr)
                larger_tail = curr
        else:
            if not median_head:
                median_head, median_tail = curr, curr
            else:
                median_tail.updateNext(curr)
                median_tail = curr
        curr = curr.nxtNode
    # supppose k = 3
    if not smaller_head:
        # [4,5,6]
        if not median_head:
            ll.head = larger_head
        # [3,3,3,3]
        elif not larger_head:
            ll.head = median_head
        # [3,4,5,6]
        else:
            median_tail.updateNext(larger_head)
            larger_tail.updateNext(ll.end)
            ll.head = median_head
    elif not median_head:
        # [1,2]
        if not larger_head:
            median_tail.updateNext(ll.end)
        # [1,2], [4,5,6]
        else:
            smaller_tail.updateNext(larger_head)
            larger_tail.updateNext(ll.end)
        ll.head = smaller_head
    # [1,2], [3,3,3], [4,5,6]
    else:
        smaller_tail.updateNext(median_head)
        median_tail.updateNext(larger_head)
        larger_tail.updateNext(ll.end)
        ll.head = smaller_head
        
def test():
    data = [3,3,3,3,3]
    ll = LinkedList()
    for i in data:
        newNode = LLNode(i, None)
        ll.appendNewNode(newNode)
    ll.printNodes()
    seperate_by_k(ll, 3)
    ll.printNodes()

test()
