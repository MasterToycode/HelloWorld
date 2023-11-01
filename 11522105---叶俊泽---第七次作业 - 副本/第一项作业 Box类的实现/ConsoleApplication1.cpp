#include"Box.h"
int main() 
{	
	float x, y, z;
	char flag = 'y';
	while (flag == 'y') 
	{
		cout << "Please input length ,width,height:";
		cin >> x>>y>>z; 
		Box box1(x, y, z);
		cout << "The perimeter,area,volume of the box1 is:" << endl;
		box1.compute_perimeter();
		box1.compute_area();
		box1.compute_volume();
		cout << endl;
		Box box2(box1);
		cout << "The perimeter, superficialarea and volume of a box with double length, width and height is as follows:" << endl;
		box2.compute_perimeter();
		box2.compute_area();
		box2.compute_volume();
		cout << endl;
		//Box box3(box2, box1);
		Box box3(x, y, z);
		box3 = box2 + box3;
		cout << "The perimeter, superficialarea and volume of a box with merging the length, width and height of box1 and box2 is as follows:" << endl;
		box3.compute_perimeter();
		box3.compute_area();
		box3.compute_volume();
		
		cout << "Do you want to continue to compute the perimeter, superficialarea and volume of a box(y or n)? ";
		cin >> flag;
	}
}