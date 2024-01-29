#include <iostream>
using namespace std;

class MyPair {
private:
    int first;
    int second;

public:
    MyPair(int a = 0, int b = 0) : first(a), second(b) {}

    MyPair operator,(const MyPair& other) const {
        cout << "Using overloaded comma operator." << endl;
        return MyPair(second, other.second);
    }

    void print() const {
       cout << "Pair: (" << first << ", " << second << ")" <<endl;
    }
};


int main() {
    MyPair pair1(1, 2);
    MyPair pair2(3, 4);
    MyPair pair3(5, 6);

    // 使用逗号运算符，返回右操作数的值
    MyPair result = (pair1, (pair2, pair3));

    std::cout << "Result of comma operator:" << std::endl;
    result.print();

    return 0;
}
