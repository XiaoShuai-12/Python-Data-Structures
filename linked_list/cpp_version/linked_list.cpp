
#include <iostream>
using namespace std;
class Node {//定义链表节点
public:
    int data;//节点数据
    Node* next;//指向下一个节点的指针
    Node(int data) {
        this->data = data;//初始化节点数据
        this->next = NULL;//初始化指向下一个节点的指针为NULL
    }
};
class LinkedList {//定义链表类
private:
    Node* head;//头指针
public:
    LinkedList() {
        head = NULL;//初始化头指针为空
    }
    void insert(int data) {//插入节点
        Node* newNode = new Node(data);//创建新节点
        if (head == NULL) {
            head = newNode;//如果链表为空，则头指针指向新节点
        }
        else {
            Node* temp = head;//否则，遍历链表找到最后一个节点
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void display() {
        Node* temp = head;//遍历链表
        while (temp!= NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.display();
    return 0;
}
