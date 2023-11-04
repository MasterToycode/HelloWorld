#include<iostream>
#include <string>
#include<vector>
using namespace std;
const int SNUM = 2;
const int TNUM = 2;
const int ANUM = 2;

class Person 
{
protected:
	 string name, gender; int age;
public:
	Person():name("/0"),gender("/0"),age(0){}
	Person(string tname, string tgender, int tage) :name(tname), gender(tgender), age(tage) {}
};








class Teacher;
class Student;
class Student : public Person 
{
protected:
	long int sno; string major;
public:
	Student() : sno(0), major("/0") {}  

	Student(string tname, string tgender, int tage,long int a,string b) :Person(tname,tgender,tage),sno(a),major(b)
	{
		Enroll();
	}

	void Enroll() { cout << "һ��ѧ��ע����ɣ�" << endl; }

	void ShowStudent() { cout << sno << "  " << name << "  " << gender << "  " << age << "  " << major << endl; }
	

	void AssignHomework( string& homework) 
	{
		cout << "������ҵ��ѧ�� " << name << "����ҵ���ݣ�" << homework << endl;
	}

	string GetName() 
	{
		return Student::name;
	}
	string GetMajor() 
	{
		return Student::major;
	}
};











class Teacher : public Person 
{
protected:
	long int tno; string college;
public:
	Teacher():tno(0),college("/0"){}

	Teacher(string tname, string tgender, int tage, long int a, string b) :Person(tname, tgender, tage), tno(a), college(b) 
	{
		Recruit();
	}

	void Recruit() { cout << "һ����ʦ��Ƹ��ɣ�" << endl; }

	void ShowTeacher()
	{
		cout << tno << "  " << name << "  " << gender << "  " << age << "  " << college << endl; 
	}

	void Course(const string  courseName, const string courseDescription, vector<Student>& studentList)
	{
		cout << "��ʦ " << Teacher::name << " ���ڹ���γ̣�" << courseName << endl;
		cout << "�γ�������" << courseDescription << endl;

	
		Student student1("��¡��", "��", 20,11522113 , "�˹�����");
		studentList.push_back(student1);

		Student student2("ʷ���", "��", 20, 11522106, "�˹�����");
		studentList.push_back(student2);

		Student student3("������", "��", 20, 11522109, "�˹�����");
		studentList.push_back(student3);

		// ʾ����������ҵ
		cout << "������ҵ��ѧ��: " << endl;

		// ʹ���ַ�����������ҵ����
		string assignment1 = "������ݿ�ϰ�⣬��ֹ���ڣ�2023-11-11";
		string assignment2 = "������ݽṹ�γ���ƣ���ֹ���ڣ�2023-11-19";


		// ����ҵ�����ѧ��
		student1.AssignHomework(assignment1);
		student2.AssignHomework(assignment2);

		cout << "��ѯ�γ�ѧ����" << endl;
		for ( Student& student : studentList) 
		{
			cout << "ѧ����" << student.GetName() << "��רҵ��" << student.GetMajor() << endl;
		}

		cout << endl;
	}

	 string GetName()
	{
		return Teacher::name;
	}
	 void LikeOrNot(Student& student, string& evaluation)
	 {
		 cout << student.GetName() << "�Խ�ʦ " << Teacher::GetName() << " ������Ϊ��" << evaluation << endl << endl;
	 }
};











class Administrator : public Person 
{
protected:
	long int ano; string section;
public:
	Administrator():ano(0),section("/0"){}

	Administrator(string tname, string tgender, int tage, long int a, string b) :Person(tname, tgender, tage), ano(a), section(b)
	{
		Employ();
	}

	void Employ() 
	{ 
		cout << "һ��������Ա��Ƹ��ɣ�" << endl;
	}

	void ShowAdministrator() 
	{ 
		cout << ano << "  " << name << "  " << gender << "  " << age << "  " << section << endl;
	}


	void ManageStudent(vector<Student>& studentList)
	{
		cout << "����Ա " << name << " ���ڽ���ѧ��ѧ������..." << endl;

		
		Student newStudent("κ��", "��", 20, 3001, "�˹�����");
		studentList.push_back(newStudent);

		// ʾ������ѯѧ����Ϣ
		cout << "��ѯѧ����Ϣ��" << endl;
		for ( Student& student : studentList) 
		{
			student.ShowStudent();
		}

	}

	void ArrangeCourse(vector<Teacher>&teacherList, vector<Student>&studentList) 
	{
			cout << "����Ա " << name << " ���ڽ��н�ʦ�γ̹���..." << endl;

			Teacher& teacher = teacherList[0]; // ����ѡ���һ����ʦ
			teacher.Course("���ѧϰ��������", "�˹����ܺ���רҵ��", studentList);

			// ʾ������ѯ�γ���Ϣ
			cout << "��ѯ�γ���Ϣ��" << endl;
			for ( Teacher& teacher : teacherList) 
			{
				teacher.ShowTeacher();
			}
	}
};











class University 
{
	string uname, uaddress;  Student s[SNUM];	Teacher t[TNUM];	Administrator a[ANUM];
	int currentTerm;  // ���ڸ��ٵ�ǰѧ��

public:
	University(string tname, string taddress, Student* sp, Teacher* tp, Administrator* ap)
		: uname(tname), uaddress(taddress),currentTerm(1)
	{
		for (int i = 0; i < SNUM; i++) { s[i] = sp[i]; }
		for (int i = 0; i < TNUM; i++) { t[i] = tp[i]; }
		for (int i = 0; i < ANUM; i++) { a[i] = ap[i]; }
	}

	void TermBegin(Administrator& ad, vector<Student>& studentList, vector<Teacher>& teacherList)
	{
		cout << "ѧУ " << uname << " �� " << currentTerm << " ѧ�ڿ�ʼע�����..." << endl;

		ad.ManageStudent(studentList);
		ad.ArrangeCourse(teacherList, studentList);
		// ���µ�ǰѧ��
		currentTerm++;
		cout << "�� " << currentTerm << " ѧ��ע����������" << endl;
	}


	void ShowUniversity()
	{
		cout << "ѧУ���ƣ�" << uname << endl;
		cout << "ѧУ��ַ��" << uaddress << endl;

		cout << "ѧ����Ϣ��" << endl;
		for (int i = 0; i < SNUM; i++) {
			s[i].ShowStudent();
		}

		cout << "��ʦ��Ϣ��" << endl;
		for (int i = 0; i < TNUM; i++) {
			t[i].ShowTeacher();
		}

		cout << "������Ա��Ϣ��" << endl;
		for (int i = 0; i < ANUM; i++) {
			a[i].ShowAdministrator();
		}
	}
};

