
class MyQueue:
    p, q = None, None
    def __init__(self):
        self.p = [] # p for push
        self.q = [] # q for pop
    def enqueue(self, value):
        self.p.append(value)
    def dequeue(self):
        if not self.q and not self.p:
            return None
        if self.q:
            return self.q.pop()
        while self.p:
            self.q.append(self.p.pop())
        return self.q.pop()


def test():
    mq = MyQueue()
    data = [1,2,3,4,5]
    for i in data:
        mq.enqueue(i)
    while True:
        value = mq.dequeue()
        if not value:
            break
        print value

test()
