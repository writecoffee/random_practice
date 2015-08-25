
from linkedlist_00_append_delete import *

def reverse_iter(ll):
    if ll.head == ll.tail:
        return
    curr = ll.head.nxtNode
    prev = ll.head
    ll.tail = prev
    prev.nxtNode = ll.end
    while curr != ll.end:
        tmpNxt = curr.nxtNode
        curr.nxtNode = prev
        prev = curr
        curr = tmpNxt
        if curr == ll.head:
            return True
    ll.head = prev
    return False

def test():
    data = [1,2,3,4,5]

    ll = LinkedList()
    for i in data:
        newNode = LLNode(i, None)
        ll.appendNewNode(newNode)
    ll.tail.updateNext(ll.head.nxtNode.nxtNode)
    return reverse_iter(ll)

print test()
