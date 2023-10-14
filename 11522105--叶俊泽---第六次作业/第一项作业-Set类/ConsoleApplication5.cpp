#include "Set.h"
int main()
{
    cout << "请输入存入数组的十个数据：" << endl;
    int* b = new int[number];
    for (int i = 0; i < number; i++)
    {
        cin >> b[i];
    }
    cout << endl;

    // 初始化Set对象
    Set mySet(b);

    // 调用Output函数输出数据
    mySet.Output();

    // 在Set对象中查找元素
    int elementToFind;
    cout << "请输入您想要查找的元素：";
    cin >> elementToFind;
    int index = mySet.Find(elementToFind);
    if (index != -1)
    {
        cout << "找到了元素 " << elementToFind << "，位于索引 " << index << endl;
    }
    else
    {
        cout << "未找到元素 " << elementToFind << endl;
    }

    // 记得释放动态分配的数组
    delete[] b;

    return 0;
}
