#include <iostream>
#include <vector>
#include <string>

using namespace std;
/* 键值对 */
struct Pair {
public:
    int key;// 键
    string val;// 值
    Pair(int key, string val) {
        this->key = key;
        this->val = val;
    }
};

/* 基于数组实现的哈希表 */
class ArrayHashMap {
private:
    vector<Pair*> buckets;// 动态数组

public:
    // 构造初始化函数
    ArrayHashMap() {
        // 初始化数组，包含 100 个桶
        buckets = vector<Pair*>(100);
    }
    // 析构函数
    ~ArrayHashMap() {
        // 释放内存
        for (const auto& bucket : buckets) {
            delete bucket;
        }
        buckets.clear();
    }

    /* 哈希函数 */
    int hashFunc(int key) {
        int index = key % 100;
        return index;
    }

    /* 查询操作 */
    string get(int key) {
        int index = hashFunc(key);
        Pair* pair = buckets[index];
        if (pair == nullptr)
            return "";
        return pair->val;
    }

    /* 添加操作 */
    void put(int key, string val) {
        Pair* pair = new Pair(key, val);
        int index = hashFunc(key);
        buckets[index] = pair;
    }

    /* 删除操作 */
    void remove(int key) {
        int index = hashFunc(key);
        // 释放内存并置为 nullptr
        delete buckets[index];
        buckets[index] = nullptr;
    }

    /* 获取所有键值对 */
    vector<Pair*> pairSet() {
        vector<Pair*> pairSet;
        for (Pair* pair : buckets) {
            if (pair != nullptr) {
                pairSet.push_back(pair);
            }
        }
        return pairSet;
    }

    /* 获取所有键 */
    vector<int> keySet() {
        vector<int> keySet;
        for (Pair* pair : buckets) {
            if (pair != nullptr) {
                keySet.push_back(pair->key);
            }
        }
        return keySet;
    }

    /* 获取所有值 */
    vector<string> valueSet() {
        vector<string> valueSet;
        for (Pair* pair : buckets) {
            if (pair != nullptr) {
                valueSet.push_back(pair->val);
            }
        }
        return valueSet;
    }

    /* 打印哈希表 */
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