#include <iostream>
#include <vector>
#include <string>

using namespace std;
/* ��ֵ�� */
struct Pair {
public:
    int key;// ��
    string val;// ֵ
    Pair(int key, string val) {
        this->key = key;
        this->val = val;
    }
};

/* ��������ʵ�ֵĹ�ϣ�� */
class ArrayHashMap {
private:
    vector<Pair*> buckets;// ��̬����

public:
    // �����ʼ������
    ArrayHashMap() {
        // ��ʼ�����飬���� 100 ��Ͱ
        buckets = vector<Pair*>(100);
    }
    // ��������
    ~ArrayHashMap() {
        // �ͷ��ڴ�
        for (const auto& bucket : buckets) {
            delete bucket;
        }
        buckets.clear();
    }

    /* ��ϣ���� */
    int hashFunc(int key) {
        int index = key % 100;
        return index;
    }

    /* ��ѯ���� */
    string get(int key) {
        int index = hashFunc(key);
        Pair* pair = buckets[index];
        if (pair == nullptr)
            return "";
        return pair->val;
    }

    /* ��Ӳ��� */
    void put(int key, string val) {
        Pair* pair = new Pair(key, val);
        int index = hashFunc(key);
        buckets[index] = pair;
    }

    /* ɾ������ */
    void remove(int key) {
        int index = hashFunc(key);
        // �ͷ��ڴ沢��Ϊ nullptr
        delete buckets[index];
        buckets[index] = nullptr;
    }

    /* ��ȡ���м�ֵ�� */
    vector<Pair*> pairSet() {
        vector<Pair*> pairSet;
        for (Pair* pair : buckets) {
            if (pair != nullptr) {
                pairSet.push_back(pair);
            }
        }
        return pairSet;
    }

    /* ��ȡ���м� */
    vector<int> keySet() {
        vector<int> keySet;
        for (Pair* pair : buckets) {
            if (pair != nullptr) {
                keySet.push_back(pair->key);
            }
        }
        return keySet;
    }

    /* ��ȡ����ֵ */
    vector<string> valueSet() {
        vector<string> valueSet;
        for (Pair* pair : buckets) {
            if (pair != nullptr) {
                valueSet.push_back(pair->val);
            }
        }
        return valueSet;
    }

    /* ��ӡ��ϣ�� */
    void print() {
        for (Pair* kv : pairSet()) {
            cout << kv->key << " -> " << kv->val << endl;
        }
    }
};
int main() {
    ArrayHashMap hashMap;
    hashMap.put(1, "apple");
    hashMap.put(2, "banana");
    hashMap.put(3, "orange");
    hashMap.put(4, "pear");
    hashMap.put(5, "grape");
    hashMap.put(6, "pineapple");
    hashMap.put(7, "watermelon");
    hashMap.put(8, "mango");
    hashMap.put(9, "peach");
    hashMap.put(10, "pear");
    hashMap.print();
    return 0;
}