
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
    ll.head = prev

def reverse_recv(ll, head):
    if head.nxtNode == ll.end:
        head.nxtNode = None
        ll.head = head
        return head
    nxt = reverse_recv(ll, head.nxtNode)
    nxt.nxtNode = head
    head.nxtNode = None
    return head

def reverse_recv_start(ll):
    head = ll.head
    nxt = reverse_recv(ll, ll.head.nxtNode)
    ll.tail = head
    nxt.nxtNode = head
    head.nxtNode = ll.end

def test():
    data = [1,2,3,4,5]
    ll = LinkedList()
    for i in data:
        newNode = LLNode(i, None)
        ll.appendNewNode(newNode)
    
    reverse_recv_start(ll)
    ll.printNodes()
    for i in reversed(data):
        newNode = LLNode(i, None)
        ll.appendNewNode(newNode)

    ll.printNodes()
    reverse_iter(ll)
    ll.printNodes()
    for i in data:
        newNode = LLNode(i, None)
        ll.appendNewNode(newNode)
    ll.printNodes()

test()
