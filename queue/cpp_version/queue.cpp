//通过数组实现队列
#include <iostream>
using namespace std;
//队列最重要的是两个指针，分别指向队首队尾，其次是队列数组，队列大小
class Queue {
private:
    int *arr; // 队列数组
    int front, rear, size; // 队头、队尾、队列大小

public:
    //构造函数，传入队列大小
    Queue(int size) {
        this->size = size;
        arr = new[size];
        front = rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }
    //判断队列是否为空
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    //判断队列是否已满
    bool isFull() {
        return (rear + 1) % size == front;
    }
    //入队
    void enqueue(int data) {
        //入队前首先判断队列是否已满
        if (isFull()) {
            cout << "队列已满！" << endl;
            return;
        }
        //入队操作，队尾指针后移，并将数据存入队尾
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = data;
    }
    //出队
    int dequeue() {
        //判断队列是否为空
        if (isEmpty()) {
            cout << "队列为空！" << endl;
            return -1;
        }
        //出队操作，队头指针后移，并返回队头元素
        int data = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return data;
    }
    //获取队头元素
    int getFront() {
        if (isEmpty()) {
            cout << "队列为空！" << endl;
            return -1;
        }
        return arr[front];
    }
    //获取队尾元素
    int getRear() {
        if (isEmpty()) {
            cout << "队列为空！" << endl;
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << "队头元素：" << q.getFront() << endl;
    cout << "队尾元素：" << q.getRear() << endl;
    q.dequeue();
    cout << "队头元素：" << q.getFront() << endl;
    cout << "队尾元素：" << q.getRear() << endl;
    q.dequeue();
    cout << "队头元素：" << q.getFront() << endl;
    cout << "队尾元素：" << q.getRear() << endl;
    q.dequeue();
    cout << "队头元素：" << q.getFront() << endl;
    cout << "队尾元素：" << q.getRear() << endl;
    q.dequeue();
    cout << "队头元素：" << q.getFront() << endl;
    cout << "队尾元素：" << q.getRear() << endl;
    q.enqueue(6);
    cout << "队头元素：" << q.getFront() << endl;
    cout << "队尾元素：" << q.getRear() << endl;
    return 0;
}