#include<iostream>
#include<math.h>
using namespace std;
class Distance;
class Point
{
	friend class Distance;
	//friend double Distance::kk(Point& a, Point& b);//��Ԫ��Ա
	/*
	 Point ����ʹ������Ԫ��Ա���� double Distance::kk(Point& a, Point& b) ������
	�������� Distance ���е�ʵ��֮ǰ������������֪�� Distance ��ľ��嶨�壬����޷���ȷ����
	 �������������� Distance ���е�һ�������Ա���� kk �� Point �����Ԫ��Ա������
	 ����������Ҫ���ڱ��� Point ��ʱ������������֪�� Distance ���� kk �����ľ���ʵ�֡�

	*/
	/*
	����Ĵ����У�friend class Distance; ���������������� Distance ���� Point �����Ԫ�࣬
	��ζ�� Point ���е����г�Ա�������ܹ����� Distance ���˽�г�Ա��
	ͨ�����������������֪�� Point ���е���Ԫ��Ա���� double Distance::kk(Point& a, Point& b); ����� Distance ���˽�г�Ա��
	��������������һ����������ˣ��ڱ��� Point ���ʱ�򣬲�����Ҫ��ǰ֪�� Distance ��ľ��嶨�塣

	�����ֻ������������Ϊ��Ԫ����ָ������ĳ�Ա�������Ͳ���Ҫ��ǰ֪����Ԫ��ľ��嶨�塣
	�������ϣ�������������ض��ĳ�Ա������Ϊ��Ԫ����ô�������ĵط�����Ҫ֪���ó�Ա�����ľ��嶨�壬��ȷ���������ܹ���ȷ����
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
	cout << "��������������ֵ(x1, y1, x2, y2): ";
	cin >> x1 >> y1 >> x2 >> y2;
	cout << "�������������ֵ��: (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ")" << endl;
	Point p3(x1, y1), p4(x2, y2);
	Distance d1;
	cout << "ͨ����Ԫ��Ա��������Ľ����: " << d1.kk(p3, p4) << endl;

}