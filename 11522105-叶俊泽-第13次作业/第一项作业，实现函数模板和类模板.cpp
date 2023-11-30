#include <iostream>
using namespace std;
// ����ģ��
template <typename T>
T compare(T a, T b)
{
    return (a > b) ? a : b;
}



// ��ģ��
template <typename T>
class Container
{
private:
    T value;
public:
    Container(T val) : value(val) {}

    T getValue()
    {
        return value;
    }

    void display()
    {
        cout << "Value in container: " << value << endl;
    }
};



int main()
{
    // ���Ժ���ģ��
    int intResult = compare(5, 10);
    double doubleResult = compare(3.14, 2.71);

    cout << "Max of 5 and 10: " << intResult << endl;
    cout << "Max of 3.14 and 2.71: " << doubleResult << endl;

    // ������ģ��
    Container<int> intContainer(42);
    Container<double> doubleContainer(3.14);

    cout << "Value in int container: " << intContainer.getValue() << endl;
    cout << "Value in double container: " << doubleContainer.getValue() << endl;

    return 0;
}
