#include <iostream>
#include <vector>
using namespace std;
// ������� Animal
class Animal {
public:
    // ���麯������ʾ���﷢����������Ϊ
    virtual void MakeSound() const = 0;

    // ����������
    virtual ~Animal() = default;
};

// ������ Lion��ʨ�ӣ�
class Lion : public Animal
{
public:
    // ʵ�ֻ����еĴ��麯��
    void MakeSound() const override
    {
        cout << "ʨ�ӷ���������" << std::endl;
    }
};


// ������ Elephant������
class Elephant : public Animal
{
public:
    // ʵ�ֻ����еĴ��麯��
    void MakeSound() const override
    {
        cout << "���󷢳�����" << endl;
    }
};

// ������ Monkey�����ӣ�
class Monkey : public Animal
{
public:
    // ʵ�ֻ����еĴ��麯��
    void MakeSound() const override
    {
        cout << "���ӷ�������ѽѽ�Ľ���" << endl;
    }
};


int main() {
    // ��������ļ���
    vector<Animal*> zoo;//������������Ϊ������
    /*
    ������ȷʵ����ֱ��ʵ�������󣬵����Դ���ָ������������ָ�롣
    ������Ĵ����У�vector<Animal*> zoo;
    �Ǵ�����һ���洢ָ�� Animal ���Ͷ����Լ������������ָ���������
    ������ֱ��ʵ���� Animal ����
    ����Ĺؼ������ڣ����ܲ��ܴ����������ʵ���������Դ���ָ����������͵�ָ�룬
    Ȼ�����������ʵ������ʼ����Щָ�롣����������У�
    zoo �д洢����ָ�� Animal ���͵�ָ�룬
    ʵ��ָ����� Lion��Elephant �� Monkey ���͵Ķ���
    */

    //vector<Animal>zoo1;����д�ͻᱨ��

    // �򼯺�����Ӳ�ͬ���͵Ķ���
    zoo.push_back(new Lion());
    zoo.push_back(new Elephant());
    zoo.push_back(new Monkey());

    // �������Ｏ�ϣ���ÿ�����﷢������
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
