
from linkedlist_append_delete import *

def findNToLast(ll, n):
    runner = ll.head
    curr = ll.head
    for i in xrange(n+1):
        curr = curr.nxtNode
    while curr != ll.end:
        curr = curr.nxtNode
        runner = runner.nxtNode
    return runner

def test():
    data = [1,2,3,4,5,6,7]
    ll = LinkedList()
    for i in data:
        newNode = LLNode(i, None)
        ll.appendNewNode(newNode)
    
    print findNToLast(ll, 2).data

test()
