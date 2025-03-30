#include <iostream>
using namespace std;
class Stack {
    private:
        int size;
        int arr*;
        int top;
    public:
        //��ʼ��
        Stack(int s){
            size = s;
            arr = new int[size];
            top = -1;
        }
        //��������
        ~Stack() {
            delete[] arr;
        }
        //��ջ
        void push(int x) {
            if (top == size - 1) {
                cout << "Stack overflow" << endl;
                return;
            }
            top++;
            arr[top] = x;
        }
        //��ջ
        int pop() {
            if (top == -1) {
                cout << "Stack underflow" << endl;
                return -1;
            }
            int x = arr[top];
            top--;
            return x;
        }
        //�鿴ջ��Ԫ��
        int peek() {
            if (top == -1) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return arr[top];
        }
        //�ж�ջ�Ƿ�Ϊ��
        bool isEmpty() {
            return (top == -1);
        }
        //�ж�ջ�Ƿ�����
        bool isFull() {
            return (top == size - 1);
        }
};
int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}