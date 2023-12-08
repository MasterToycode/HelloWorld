#include<iostream>

using namespace std;

class Rational {
private:
    int numerator;   // 分子
    int denominator; // 分母

public:
    // 构造函数
    Rational(int num, int den) : numerator(num), denominator(den) {
        simplify();  // 简化有理数
    }

    // 求最大公约数
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }
    //妙
    /*
    在欧几里得算法（Euclidean Algorithm）中，最大公约数的计算是通过反复用较小的数去除较大的数，
    然后用较大的数去除余数，直到余数为零。这一过程中，被除数和除数的余数之间的关系可以用递归的方式表示
    */

    // 简化有理数
    void simplify() {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;

        // 处理负数的情况
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // 重载+运算符
    Rational operator+(const Rational& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    // 重载-运算符
    Rational operator-(const Rational& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    // 重载*运算符
    Rational operator*(const Rational& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    // 重载/运算符
    Rational operator/(const Rational& other) const {
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Rational(num, den);
    }

    // 显示有理数
    void display() const {
        cout << this->numerator << "/" << this->denominator;
    }
};

int main() {
    // 输入有理数对象的分子和分母
    int num1, den1, num2, den2;
    cout << "Enter the first rational number (numerator denominator): ";
    cin >> num1 >> den1;
    cout << "Enter the second rational number (numerator denominator): ";
    cin >> num2 >> den2;

    // 创建有理数对象
    Rational r1(num1, den1);
    Rational r2(num2, den2);

    // 进行有理数加法
    Rational sum = r1 + r2;
    cout << "Sum: ";
    sum.display();
    cout << endl;

    // 进行有理数减法
    Rational diff = r1 - r2;
    cout << "Difference: ";
    diff.display();
    cout << endl;

    // 进行有理数乘法
    Rational product = r1 * r2;
    cout << "Product: ";
    product.display();
    cout << endl;

    // 进行有理数除法
    Rational quotient = r1 / r2;
    cout << "Quotient: ";
    quotient.display();
    cout << endl;

    return 0;
}
