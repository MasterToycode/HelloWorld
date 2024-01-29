#include <iostream>
#include <vector>
#include <algorithm>  // 用于使用min
using namespace std;
template<typename T>
/*
模板函数有一个特点：虽然模板类型参数T可以实例化成各种类型，
但是采用模板类型参数T的各参数之间必须保持完全一致的类型。
模板类型不具有隐式类型转换的能力，
例如int与char、float与int、float与double等之间的隐式类型转换
*/
T cal(vector<T>* a)
{
    T temp = *min_element(a->begin(), a->end());
    for (int i = 0; i < a->size(); i++)
    {
    }
    return temp;
}


/*
由于模板主要是为函数或类安排的，
所以模板声明语句必须置于相关函数或类的声明和定义语句之前，
但附于函数声明语句和定义语句前的模板参数表的替代类型标识符可以不一致。
函数模板定义不是一个实实在在的函数，编译系统不为其产生任何执行代码。
*/

int main()
{
    vector<int> intVec = { 3, 1, 4, 1, 5, 9, 2, 6 };
    cout << "Minimum value: " << cal(&intVec) << endl;

    vector<double> doubleVec = { 3.14, 2.71, 1.618 };
    cout << "Minimum value: " << cal(&doubleVec) << endl;

    return 0;
}

/*
一般情况下，对内联函数还有如下的限制：
   (1) 不能包含递归
   (2) 不能包含静态数据
   (3) 不能包含循环
   (4) 不能包含switch和goto语句
   (5) 不能包含数组
若一个内联函数定义不能满足以上限制，则编译系统将自动把它当作普通函数处理


如果函数有多个默认参数，则默认参数必须是从右向左设置，
并且在一个默认参数的右边不能有未指定默认值的参数
void fun(int a=3, int b=6, int c, int d);
void fun(int a=65, int b=3, int c, int d=3);
需要注意的是，如果函数原型声明中设置了默认参数，
则不可再在函数定义的头部重复设置
（即函数原型声明和定义头部只能有一处设置默认参数，不可同时设置），
否则编译时出错


*/


