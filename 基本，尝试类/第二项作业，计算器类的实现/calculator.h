#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
class calculator
{
	private:
	double number1, number2, result;
	char sign;

	public:
		calculator(double x,double y,char z) :number1(x), number2(y),sign(z)
		{
			result = 0;
		};
		~calculator() 
		{
		};
		double opearation(double x, double y, char z);
};	

double calculator::opearation(double x, double y, char z) 
{
	switch (z)
	{
	case '+':
		result = x + y;
		break;
	case '-':
		result = x - y;
		break;
	case '*':
		result = x * y;
		break;
	case '/':
		if (y == 0) { cout << "y��Ϊ����������Ϊ0��" << endl; break; }
		result = x / y;
		break;
	case '%':
		if (x == static_cast<int>(x) && y == static_cast<int>(y)) {
			// x��y��������
			result = static_cast<int>(x) % static_cast<int>(y);
		}
		else {
			// x��y�������������������Ϣ��������ǰ����
			cout << "����x��y������������" << endl;
		}
		break; 
	case '^':
		result = pow(x,y);
		break;
	default:cout << "����������Ч�Ĳ�����" << endl; 
	}
	return result;
}


