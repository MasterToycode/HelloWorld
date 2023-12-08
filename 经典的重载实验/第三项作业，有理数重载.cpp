#include<iostream>

using namespace std;

class Rational {
private:
    int numerator;   // ����
    int denominator; // ��ĸ

public:
    // ���캯��
    Rational(int num, int den) : numerator(num), denominator(den) {
        simplify();  // ��������
    }

    // �����Լ��
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }
    //��
    /*
    ��ŷ������㷨��Euclidean Algorithm���У����Լ���ļ�����ͨ�������ý�С����ȥ���ϴ������
    Ȼ���ýϴ����ȥ��������ֱ������Ϊ�㡣��һ�����У��������ͳ���������֮��Ĺ�ϵ�����õݹ�ķ�ʽ��ʾ
    */

    // ��������
    void simplify() {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;

        // �����������
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // ����+�����
    Rational operator+(const Rational& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    // ����-�����
    Rational operator-(const Rational& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    // ����*�����
    Rational operator*(const Rational& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    // ����/�����
    Rational operator/(const Rational& other) const {
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Rational(num, den);
    }

    // ��ʾ������
    void display() const {
        cout << this->numerator << "/" << this->denominator;
    }
};

int main() {
    // ��������������ķ��Ӻͷ�ĸ
    int num1, den1, num2, den2;
    cout << "Enter the first rational number (numerator denominator): ";
    cin >> num1 >> den1;
    cout << "Enter the second rational number (numerator denominator): ";
    cin >> num2 >> den2;

    // ��������������
    Rational r1(num1, den1);
    Rational r2(num2, den2);

    // �����������ӷ�
    Rational sum = r1 + r2;
    cout << "Sum: ";
    sum.display();
    cout << endl;

    // ��������������
    Rational diff = r1 - r2;
    cout << "Difference: ";
    diff.display();
    cout << endl;

    // �����������˷�
    Rational product = r1 * r2;
    cout << "Product: ";
    product.display();
    cout << endl;

    // ��������������
    Rational quotient = r1 / r2;
    cout << "Quotient: ";
    quotient.display();
    cout << endl;

    return 0;
}
