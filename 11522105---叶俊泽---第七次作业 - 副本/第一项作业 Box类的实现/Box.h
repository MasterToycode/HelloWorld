#include<iostream>
using namespace std;
class Box 
{
private:
	float length;
	float height;
	float width;
	float perimeter;
	float area;
	float volume;
public:
	Box(float x,float y,float z) :length(x), width(y), height(z) 
	{
		area = 0;
		perimeter = 0;
		volume = 0;
	}
	Box(Box& other)
	{	
		length = other.length * 2;
		width = other.width * 2;
		height = other.height * 2;
	}
	Box( Box& box1, Box& box2) : length(box1.length + box2.length), width(box1.width + box2.width), height(box1.height + box2.height)
	{
	}
	Box operator+(Box& other) 
	{	
		   Box temp(length + other.length, width + other.width, height + other.height);
		   return temp;
	}

	Box operator+(float value) 
	{
		Box temp(length + value, width + value, height + value);
		return temp;
	}
	void compute_perimeter();
	void compute_area();
	void compute_volume();
};
void Box::compute_perimeter() 
{
	perimeter = 2 * (length + height + width);
	cout << perimeter << endl;
}
void Box::compute_area() 
{
	area = 2 * (length * height + length * width + height * width);
	cout << area << endl;
}
void Box::compute_volume() 
{
	volume = height * length * width;
	cout << volume << endl;
}