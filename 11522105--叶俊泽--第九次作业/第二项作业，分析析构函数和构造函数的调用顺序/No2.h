#include<iostream>
using namespace std;
class Ancestor 
{
protected:
	string Aname;//���ȵ�����
	char Agender;//���ȵ��Ա�
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
	string Gname;//�汲������
	char Ggender;//�汲���Ա�
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
		cout << "���汲�е������ȵĳ�Ա����" << endl << endl;
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
		cout << "�ڸ����е����汲�ĳ�Ա����" << endl << endl;
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
		cout << "��ƽ���е��ø����ĳ�Ա����" << endl << endl;
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
		cout << "��ƽ���е��ø����ĳ�Ա����" << endl << endl;
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
		cout << "�����е��ø����ĳ�Ա����" << endl << endl;
		Bro.displayMyself();
		cout << "��ƽ���е���ƽ���ĳ�Ա����" << endl << endl;
		Sis.displayMyself();
		cout << "��ƽ���е���ƽ���ĳ�Ա����" << endl << endl;
		cout << "The information of Me is: " << Mname << "  " << Mgender << endl;
	}
	~Me() { cout << "The Me is unconstructed!" << endl; }
};

