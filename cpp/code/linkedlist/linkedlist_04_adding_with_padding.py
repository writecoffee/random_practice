
from linkedlist_00_append_delete import *

def insertAtHead(ll, data):
    newNode = LLNode(data, ll.head)
    newNode.nxtNode = ll.head
    ll.head = newNode

def padding(ll1, ll2):
    global length
    length = 0
    i1 = ll1.head
    i2 = ll2.head
    diff = 0
    while i1 != ll1.end and i2 != ll2.end:
        length += 1
        i1 = i1.nxtNode
        i2 = i2.nxtNode
    if i1 == ll1.end and i2 == ll2.end:
        return 0
    if i1 == ll1.end:
        while i2 != ll2.end:
            length += 1
            i2 = i2.nxtNode
            insertAtHead(ll1, 0)
            diff += 1
        return diff
    if i1 == ll1.end:
        while i1 != ll1.end:
            length += 1
            i1 = i1.nxtNode
            insertAtHead(ll2, 0)
            diff -= 1
        return diff

def addRecur(n1, n2, n, ll):
    global length
    if n == length:
        result = n1.data + n2.data
        ll.tail = LLNode(result % 10, ll.end)
        return ll.tail, result / 10
    lowerNode, lowerCarry = addRecur(n1.nxtNode, n2.nxtNode, n + 1, ll)
    result = n1.data + n2.data + lowerCarry
    return LLNode(result % 10, lowerNode), result / 10

def adding(ll1, ll2):
    padding(ll1, ll2)
    ll = LinkedList() 
    newHead, carry = addRecur(ll1.head, ll2.head, 1, ll)
    ll.head = newHead
    if carry > 0:
        insertAtHead(ll, carry)
    return ll

def test():
    data1 = [2,3,4,5]
    ll1 = LinkedList()
    for i in data1:
        newNode = LLNode(i, None)
        ll1.appendNewNode(newNode)
    ll1.printNodes()
    data2 = [9,9,3,4,5]
    ll2 = LinkedList()
    for i in data2:
        newNode = LLNode(i, None)
        ll2.appendNewNode(newNode)
    ll2.printNodes()
    ll = adding(ll1, ll2)
    ll.printNodes()

test()
