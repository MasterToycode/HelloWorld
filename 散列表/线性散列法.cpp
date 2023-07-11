#include <iostream>
using namespace std;
//结构体定义：
struct HashNode
{
    int key;  // 键值
    int data;  // 数据
};

void linearProbing(int& index, int m)
{
    index = (index + 1) % m;  // 线性探测再散列
}

//哈希表的创建函数：
void createHashTable(HashNode* hashTable, int m, int p, int n)
{
    // 初始化哈希表
    for (int i = 0; i < m; i++)
    {
        hashTable[i].key = -1;  // 将所有关键字置为-1表示空
        hashTable[i].data = -1;
    }
    // 读入数据并插入哈希表
    for (int i = 0; i < n; i++)
    {
        int key, data;
        cin >> key >> data;//刚开始并没有直接将数据存入哈希表。
        int index = key % p;  // 哈希函数计算哈希地址
        // 处理冲突
        while (hashTable[index].key != -1) //初始值不等于-1，说明已经有数据存入！
        {
            linearProbing(index, m);  // 线性探测再散列
        }
        // 将记录插入哈希表
        hashTable[index].key = key;
        hashTable[index].data = data;
    }
}

//线性探测再散列函数：
// 在哈希表中查找指定关键字，返回是否查找成功
// 参数：
//   hashTable - 哈希表数组
//   m - 哈希表大小
//   key - 待查找的关键字
//   index - 查找结果的哈希地址
// 返回值：
//   是否查找成功
bool searchHashTable(HashNode* hashTable, int m, int key, int& index)
{
    index = key % m;  // 哈希函数计算哈希地址
    // 在哈希表中查找关键字
    while (hashTable[index].key != -1) //关键字不为-1；说明存在数据才能进入循环继续查找
    {
        if (hashTable[index].key == key) //关键字相同
        {
            return true;
        }
        linearProbing(index, m);  // 冲突处理，线性探测法（没有找到对应的关键值，存在冲突，继续查找）
    }
    return false;
}

//主函数
int main() {
    //输入哈希表大小、哈希函数参数p、数据个数n
    int m, p, n;
    cin >> m >> p >> n;

    //创建哈希表
    HashNode* hashTable = new HashNode[m];
    createHashTable(hashTable, m, p, n);

    //输入待查找的关键字
    int key;
    cin >> key;

    int index;
    //查找关键字在哈希表中的位置
    if (searchHashTable(hashTable, m, key, index))
    {
        cout << "Find " << index << endl;
        //输出对应的键值对
        cout << hashTable[index].key << " " << hashTable[index].data << endl;
    }
    else
    {
        cout << "NotFind" << endl;
    }

    //释放哈希表的内存
    delete[] hashTable;
    return 0;
}