
from linkedlist_00_append_delete import *

def check_palindrome_iter(ll):
    runner, runnee = ll.head, ll.head.nxtNode
    stack = []
    while runnee != ll.end:
        stack += [runner.data]
        runner = runner.nxtNode
        if runnee.nxtNode != ll.end:
            runnee = runnee.nxtNode.nxtNode
        # odd number of nodes
        else:
            runnee = ll.end
            # remove the mid element from stack
            stack.pop()
    # compare the front and the end point
    runner = runner.nxtNode
    while runner != ll.end:
        if stack.pop() != runner.data:
            return False
        runner = runner.nxtNode
    return True

def check_palindrome_recv(curHead, curLength):
    if curLength == 0:
        return curHead
    # odd number of nodes
    if curLength == 1:
        return curHead.nxtNode
    result = check_palindrome_recv(curHead.nxtNode, curLength - 2)
    print result.data
    if curHead.data != result.data:
        return None
    else:
        return result.nxtNode

def test():
    data = [1,2,3,3,2,1]
    ll = LinkedList()
    for i in data:
        newNode = LLNode(i, None)
        ll.appendNewNode(newNode)
    print check_palindrome_iter(ll)

def test_recv():
    data = [1,2,3,3,2,1]
    ll = LinkedList()
    for i in data:
        newNode = LLNode(i, None)
        ll.appendNewNode(newNode)
    print check_palindrome_recv(ll.head, len(data)) == ll.end

test()
test_recv()
