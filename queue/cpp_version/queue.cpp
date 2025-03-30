//ͨ������ʵ�ֶ���
#include <iostream>
using namespace std;
//��������Ҫ��������ָ�룬�ֱ�ָ����׶�β������Ƕ������飬���д�С
class Queue {
private:
    int *arr; // ��������
    int front, rear, size; // ��ͷ����β�����д�С

public:
    //���캯����������д�С
    Queue(int size) {
        this->size = size;
        arr = new[size];
        front = rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }
    //�ж϶����Ƿ�Ϊ��
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    //�ж϶����Ƿ�����
    bool isFull() {
        return (rear + 1) % size == front;
    }
    //���
    void enqueue(int data) {
        //���ǰ�����ж϶����Ƿ�����
        if (isFull()) {
            cout << "����������" << endl;
            return;
        }
        //��Ӳ�������βָ����ƣ��������ݴ����β
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = data;
    }
    //����
    int dequeue() {
        //�ж϶����Ƿ�Ϊ��
        if (isEmpty()) {
            cout << "����Ϊ�գ�" << endl;
            return -1;
        }
        //���Ӳ�������ͷָ����ƣ������ض�ͷԪ��
        int data = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return data;
    }
    //��ȡ��ͷԪ��
    int getFront() {
        if (isEmpty()) {
            cout << "����Ϊ�գ�" << endl;
            return -1;
        }
        return arr[front];
    }
    //��ȡ��βԪ��
    int getRear() {
        if (isEmpty()) {
            cout << "����Ϊ�գ�" << endl;
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
    cout << "��ͷԪ�أ�" << q.getFront() << endl;
    cout << "��βԪ�أ�" << q.getRear() << endl;
    q.dequeue();
    cout << "��ͷԪ�أ�" << q.getFront() << endl;
    cout << "��βԪ�أ�" << q.getRear() << endl;
    q.dequeue();
    cout << "��ͷԪ�أ�" << q.getFront() << endl;
    cout << "��βԪ�أ�" << q.getRear() << endl;
    q.dequeue();
    cout << "��ͷԪ�أ�" << q.getFront() << endl;
    cout << "��βԪ�أ�" << q.getRear() << endl;
    q.dequeue();
    cout << "��ͷԪ�أ�" << q.getFront() << endl;
    cout << "��βԪ�أ�" << q.getRear() << endl;
    q.enqueue(6);
    cout << "��ͷԪ�أ�" << q.getFront() << endl;
    cout << "��βԪ�أ�" << q.getRear() << endl;
    return 0;
}