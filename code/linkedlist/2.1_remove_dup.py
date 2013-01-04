
from linkedlist_00_append_delete import *

def removeDuplicate(ll):
    runner = None
    curr = ll.head
    while curr != ll.end:
        runner = ll.head
        while runner != curr:
            if runner.data == curr.data:
                ll.deleteNode(runner.data)
            runner = runner.nxtNode
        curr = curr.nxtNode

def test():
    data = [1,2,2,3,4,5,5,5]
    ll = LinkedList()
    for i in data:
        newNode = LLNode(i, None)
        ll.appendNewNode(newNode)
    
    removeDuplicate(ll)
    ll.printNodes()

test()
