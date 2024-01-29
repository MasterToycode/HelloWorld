#include<iostream>
#include<math.h>
using namespace std;
class Distance;
class Point
{
	friend class Distance;
	//friend double Distance::kk(Point& a, Point& b);//友元成员
	/*
	 Point 类中使用了友元成员函数 double Distance::kk(Point& a, Point& b) 的声明
	，但是在 Distance 类中的实现之前，编译器并不知道 Distance 类的具体定义，因此无法正确处理。
	 这句代码是在声明 Distance 类中的一个具体成员函数 kk 是 Point 类的友元成员函数。
	 这样的声明要求在编译 Point 类时，编译器必须知道 Distance 类中 kk 函数的具体实现。

	*/
	/*
	在你的代码中，friend class Distance; 这句代码声明了整个 Distance 类是 Point 类的友元类，
	意味着 Point 类中的所有成员函数都能够访问 Distance 类的私有成员。
	通过这个声明，编译器知道 Point 类中的友元成员函数 double Distance::kk(Point& a, Point& b); 会访问 Distance 类的私有成员，
	而不仅仅是其中一个函数。因此，在编译 Point 类的时候，不再需要提前知道 Distance 类的具体定义。

	如果你只声明整个类作为友元而不指定具体的成员函数，就不需要提前知道友元类的具体定义。
	但如果你希望声明并定义特定的成员函数作为友元，那么在声明的地方就需要知道该成员函数的具体定义，以确保编译器能够正确处理。
	*/
private:
	double x, y;
public:
	Point(double a, double b)
	{
		x = a;
		y = b;
	}
};


class Distance
{
public:
	double kk(Point& a, Point& b)
	{
		double temp;
		temp = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
		return temp;
	}
};



int main()
{
	int x1, x2, y1, y2;
	cout << "请输入两个坐标值(x1, y1, x2, y2): ";
	cin >> x1 >> y1 >> x2 >> y2;
	cout << "输入的两个坐标值是: (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ")" << endl;
	Point p3(x1, y1), p4(x2, y2);
	Distance d1;
	cout << "通过友元成员函数计算的结果是: " << d1.kk(p3, p4) << endl;

}