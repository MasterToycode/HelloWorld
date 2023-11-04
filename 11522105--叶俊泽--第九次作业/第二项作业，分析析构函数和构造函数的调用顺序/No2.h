#include<iostream>
using namespace std;
class Ancestor 
{
protected:
	string Aname;//祖先的名字
	char Agender;//祖先的性别
public:
	Ancestor(string name, char gender) :Aname(name), Agender(gender) 
	{ cout << "The Ancestor is constructed!" << endl<<endl; }


	void displayAncestor() 
	{ cout << "The information of my Ancestor is: " << Aname << "  " << Agender << endl<<endl; }
	
	~Ancestor() 
	{ cout << "The Ancestor is unconstructed!" << endl<<endl; }
};




class GrandFather : public Ancestor 
{
protected:
	string Gname;//祖辈的姓名
	char Ggender;//祖辈的性别
public:

	GrandFather(string name1, char gender1, string name2, char gender2):Ancestor(name1,gender1) 
	{
		Gname = name2;
		Ggender = gender2;
		{cout << "The Grandather is constructed!" << endl<<endl; }
	}

	void displayMyself() 
	{ cout << "The information of my GrandFather is: " << Gname << "  " << Ggender << endl<<endl; }

	void displayGrandFather() 
	{ 
		displayAncestor(); 
		cout << "在祖辈中调用祖先的成员函数" << endl << endl;
		displayMyself();
	}

	~GrandFather() { cout << "The GrandFather is unconstructed!" << endl<<endl; }
};




class Father : public GrandFather 
{
protected:
	string Fname;	char Fgender;
public:
	Father(string name1, char gender1, string name2, char gender2, string name3, char gender3) :GrandFather(name1,gender1,name2,gender2)
	{
		Fname = name3;
		Fgender = gender3;
		cout << "The Father is constructed!" << endl; 
	}

	void displayMyself() 
	{ cout << "The information of my Father is: " << Fname << "  " << Fgender << endl<<endl; }

	void displayFather() 
	{ 
		displayGrandFather();
		cout << "在父辈中调用祖辈的成员函数" << endl << endl;
		displayMyself();
	}
	~Father() { cout << "The Father is unconstructed!" << endl; }
};




class Brother : public Father 
{
protected:
	string Bname;	char Bgender;
public:
	Brother(string name1, char gender1, string name2, char gender2, string name3, char gender3, string name4, char gender4) :Father(name1,gender1,name2,gender2,name3,gender3)
	{
		Bname = name4;
		Bgender = gender4;
		cout << "The Brother is constructed!" << endl; 
	}

	void displayMyself() 
	{ cout << "The information of my Brother is: " << Bname << "  " << Bgender << endl<<endl; }

	void displayBrother() 
	{	
		displayFather(); 
		cout << "在平辈中调用父辈的成员函数" << endl << endl;
		displayMyself();
	}

	~Brother() { cout << "The Brother is unconstructed!" << endl; }
};





class Sister : public Father
{
protected:
	string Sname;	char Sgender;
public:
	Sister(string name1, char gender1, string name2, char gender2, string name3, char gender3, string name4, char gender4) :Father(name1, gender1, name2, gender2, name3, gender3)
	{
		Sname = name4;
		Sgender = gender4;
		cout << "The Sister is constructed!" << endl;
	}

	void displayMyself() 
	{ cout << "The information of my Sister is: " << Sname << "  " << Sgender << endl; }

	void displayBrother()
	{
		displayFather();
		cout << "在平辈中调用父辈的成员函数" << endl << endl;
		displayMyself();
	}

	~Sister() { cout << "The Sister is unconstructed!" << endl; }
};


class Me : public Father {
protected:
	string Mname;
	char Mgender;
	Sister Sis;
	Brother Bro;
public:
	Me(string name1, char gender1, string name2, char gender2, string name3, char gender3, string name4, char gender4, Brother tbro, Sister tsis)
		: Father(name1, gender1, name2, gender2, name3, gender3), Sis(tsis), Bro(tbro)
	{
		Mname = name4;
		Mgender = gender4;

		cout << "The Me is constructed!" << endl;
	}

	void displayMe() {
		displayFather();
		cout << "在晚辈中调用父辈的成员函数" << endl << endl;
		Bro.displayMyself();
		cout << "在平辈中调用平辈的成员函数" << endl << endl;
		Sis.displayMyself();
		cout << "在平辈中调用平辈的成员函数" << endl << endl;
		cout << "The information of Me is: " << Mname << "  " << Mgender << endl;
	}
	~Me() { cout << "The Me is unconstructed!" << endl; }
};

