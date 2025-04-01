#哈希表实现
class HashTable:
    # 构造函数
    def __init__(self, size=100):
        self.size = size
        self.table = [[] for _ in range(size)]# 初始化哈希表，每个元素是一个列表

    def hash(self, key):# 哈希函数
        return hash(key) % self.size

    def insert(self, key, value):# 插入元素
        index = self.hash(key)
        self.table[index].append((key, value))

    def get(self, key):# 获取元素
        index = self.hash(key)
        for item in self.table[index]:
            if item[0] == key:
                return item[1]
        return None

    def delete(self, key):# 删除元素
        index = self.hash(key)
        for i, item in enumerate(self.table[index]):
            if item[0] == key:
                del self.table[index][i]
                return True
        return False
    def show(self):
        for i in self.table:
            print(i)

ht  = HashTable()
ht.insert("apple", 10)
ht.insert("banana", 20)
ht.insert("orange", 30)
print("apple:", ht.get("apple") )# 10
ht.show()
ht.delete("banana")
ht.show()