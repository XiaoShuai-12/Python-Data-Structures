class Stack:
    def __init__(self,max_size=None):
        '''初始化栈
        ：param max_size: 栈的最大容量，默认为None，表示栈的大小没有限制
        '''
        self.stack = []
        self.max_size = max_size
    def push(self,item):
        '''入栈
        ：param item: 入栈的元素
        '''
        if self.is_full():
            raise Exception("Stack is full")
        self.stack.append(item)

    def pop(self):
        '''出栈
        return: 栈顶的元素'''
        if self.is_empty():
            raise Exception("Stack is empty")
        return self.stack.pop()

    def peek(self):
        '''查看栈顶元素
        return: 栈顶的元素'''
        if self.is_empty():
            raise Exception("Stack is empty")
        return self.stack[-1]

    def is_empty(self):
        '''判断栈是否为空
        return: True/False'''
        return len(self.stack) == 0

    def is_full(self):
        '''判断栈是否已满
        return: True/False'''
        if self.max_size is None:
            return False
        return len(self.stack) == self.max_size

    def size(self):
        '''返回栈的大小
        return: 栈的大小'''
        return len(self.stack)

    def clear(self):
        '''清空栈'''
        self.stack = []

    def __str__(self):
        '''打印栈'''
        return str(self.stack)

# Example usage:
if __name__ == '__main__':
    stack = Stack(max_size=5)

    #入栈
    stack.push(1)
    stack.push(2)
    stack.push(3)
    stack.push(4)
    stack.push(5)
    print(stack) # [1, 2, 3, 4, 5]

    try:
        stack.push(6) # 栈已满，抛出异常
    except Exception as e:
        print(f"Error: {e}") # Stack is full

    #出栈
    print("Popped:", stack.pop())
    print(stack) # [1, 2, 3, 4]

    #查看栈顶元素
    print("Peeked:", stack.peek())
    print(stack) # [1, 2, 3, 4]

    #判断栈是否为空
    print("Is empty:", stack.is_empty()) # False

    #判断栈是否已满
    print("Is full:", stack.is_full()) # False

    #返回栈的大小
    print("Size:", stack.size()) # 4

    #清空栈
    stack.clear()
    print(stack) # []
    