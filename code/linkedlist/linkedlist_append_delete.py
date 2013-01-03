
class LLNode:
    data = None
    nxtNode = None
    def __init__(self, data, nxtNode):
        self.data = data
        self.nxtNode = nxtNode
    def updateNext(self, newNxtNode):
        self.nxtNode = newNxtNode

class LinkedList:
    head = None
    tail = None
    end = None
    def __init__(self):
        # create dummpy end node
        end = LLNode(None, None)
    def appendNewNode(self, newNode):
        if not self.head:
            newNode.updateNext(self.end)
            self.head = self.tail = newNode
        else:
            newNode.updateNext(self.end)
            self.tail.updateNext(newNode)
            self.tail = newNode
    def isExists(self, data):
        curr = self.head
        while curr != self.end:
            if curr.data == data:
                return curr
            curr = curr.nxtNode
        return None
    def deleteNode(self, data):
        if self.head is None:
            return False
        curr = self.head
        prev = None
        # head node match
        if curr.data == data:
            if self.head == self.tail:
                self.head = self.tail = curr.nxtNode
            else:
                self.head = curr.nxtNode
            return True
        else:
            prev = curr
            curr = curr.nxtNode
        while curr != self.end:
            if curr.data == data:
                if curr == self.tail:
                    prev.nxtNode = self.end
                    self.tail = prev
                else:
                    prev.nxtNode = curr.nxtNode
                return True
            prev = curr
            curr = curr.nxtNode
        return False
    def printNodes(self):
        curr = self.head
        while (curr != self.end):
            print curr.data,
            curr = curr.nxtNode
        print
        

def test():
    data = [1,2,3,4,5]
    ll = LinkedList()
    for i in data:
        newNode = LLNode(i, None)
        ll.appendNewNode(newNode)
    
    print ll.deleteNode(data[0])
    ll.printNodes()
    for i in reversed(data):
        print ll.deleteNode(i)
        ll.printNodes()

#test()
