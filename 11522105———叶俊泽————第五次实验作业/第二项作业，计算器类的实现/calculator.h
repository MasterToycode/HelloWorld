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
		if (y == 0) { cout << "y作为被除数不能为0！" << endl; break; }
		result = x / y;
		break;
	case '%':
		if (x == static_cast<int>(x) && y == static_cast<int>(y)) {
			// x和y都是整数
			result = static_cast<int>(x) % static_cast<int>(y);
		}
		else {
			// x和y不是整数，输出错误信息并跳过当前计算
			cout << "错误：x和y必须是整数。" << endl;
		}
		break; 
	case '^':
		result = pow(x,y);
		break;
	default:cout << "输入错误或无效的操作！" << endl; 
	}
	return result;
}


