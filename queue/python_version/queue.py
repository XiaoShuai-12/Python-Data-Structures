class Queue:
    #初始化队列
    def __init__(self):
        self.items = []
    #入队
    def enqueue(self, item):
        self.items.append(item)
    #出队
    def dequeue(self):
        if not self.is_empty():
            return self.items.pop(0)
        else:
            return None
    #判断队列是否为空
    def is_empty(self):
        return len(self.items) == 0
    #获取队列长度
    def size(self):
        return len(self.items)
    #获取队列头部元素
    def peek(self):
        if not self.is_empty():
            return self.items[0]
        else:
            return None
    #打印队列
    def print_queue(self):
        print(self.items)

#测试
q = Queue()
#入队
q.enqueue(1)
q.print_queue()
q.enqueue(2)
q.print_queue()
q.enqueue(3)
#打印队列
q.print_queue()
#出队
q.dequeue()
#打印出队后队列
q.print_queue()
q.dequeue()
q.print_queue()
q.dequeue()
q.print_queue()
q.dequeue()