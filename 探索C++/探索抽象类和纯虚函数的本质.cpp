#include <iostream>
#include <vector>
using namespace std;
// 抽象基类 Animal
class Animal {
public:
    // 纯虚函数，表示动物发出声音的行为
    virtual void MakeSound() const = 0;

    // 虚析构函数
    virtual ~Animal() = default;
};

// 派生类 Lion（狮子）
class Lion : public Animal
{
public:
    // 实现基类中的纯虚函数
    void MakeSound() const override
    {
        cout << "狮子发出咆哮声" << std::endl;
    }
};


// 派生类 Elephant（大象）
class Elephant : public Animal
{
public:
    // 实现基类中的纯虚函数
    void MakeSound() const override
    {
        cout << "大象发出嘟嘟声" << endl;
    }
};

// 派生类 Monkey（猴子）
class Monkey : public Animal
{
public:
    // 实现基类中的纯虚函数
    void MakeSound() const override
    {
        cout << "猴子发出咿咿呀呀的叫声" << endl;
    }
};


int main() {
    // 创建动物的集合
    vector<Animal*> zoo;//这个数组的类型为动物类
    /*
    抽象类确实不能直接实例化对象，但可以创建指向派生类对象的指针。
    在上面的代码中，vector<Animal*> zoo;
    是创建了一个存储指向 Animal 类型对象（以及其派生类对象）指针的容器，
    而不是直接实例化 Animal 对象。
    这里的关键点在于，尽管不能创建抽象类的实例，但可以创建指向抽象类类型的指针，
    然后用派生类的实例来初始化这些指针。在这个例子中，
    zoo 中存储的是指向 Animal 类型的指针，
    实际指向的是 Lion、Elephant 和 Monkey 类型的对象。
    */

    //vector<Animal>zoo1;这样写就会报错！

    // 向集合中添加不同类型的动物
    zoo.push_back(new Lion());
    zoo.push_back(new Elephant());
    zoo.push_back(new Monkey());

    // 遍历动物集合，让每个动物发出声音
    for (const auto& animal : zoo) 
    {
        animal->MakeSound();
    }

    for (const auto& animal : zoo) 
    {
        delete animal;
    }
    return 0;
}
