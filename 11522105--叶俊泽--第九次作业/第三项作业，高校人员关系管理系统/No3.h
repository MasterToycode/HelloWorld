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

	void Enroll() { cout << "一个学生注册完成！" << endl; }

	void ShowStudent() { cout << sno << "  " << name << "  " << gender << "  " << age << "  " << major << endl; }
	

	void AssignHomework( string& homework) 
	{
		cout << "分配作业给学生 " << name << "，作业内容：" << homework << endl;
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

	void Recruit() { cout << "一个教师招聘完成！" << endl; }

	void ShowTeacher()
	{
		cout << tno << "  " << name << "  " << gender << "  " << age << "  " << college << endl; 
	}

	void Course(const string  courseName, const string courseDescription, vector<Student>& studentList)
	{
		cout << "教师 " << Teacher::name << " 正在管理课程：" << courseName << endl;
		cout << "课程描述：" << courseDescription << endl;

	
		Student student1("宋隆瑞", "男", 20,11522113 , "人工智能");
		studentList.push_back(student1);

		Student student2("史嘉炜", "男", 20, 11522106, "人工智能");
		studentList.push_back(student2);

		Student student3("李玉林", "男", 20, 11522109, "人工智能");
		studentList.push_back(student3);

		// 示例：分配作业
		cout << "分配作业给学生: " << endl;

		// 使用字符串来代替作业描述
		string assignment1 = "完成数据库习题，截止日期：2023-11-11";
		string assignment2 = "完成数据结构课程设计，截止日期：2023-11-19";


		// 将作业分配给学生
		student1.AssignHomework(assignment1);
		student2.AssignHomework(assignment2);

		cout << "查询课程学生：" << endl;
		for ( Student& student : studentList) 
		{
			cout << "学生：" << student.GetName() << "，专业：" << student.GetMajor() << endl;
		}

		cout << endl;
	}

	 string GetName()
	{
		return Teacher::name;
	}
	 void LikeOrNot(Student& student, string& evaluation)
	 {
		 cout << student.GetName() << "对教师 " << Teacher::GetName() << " 的评价为：" << evaluation << endl << endl;
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
		cout << "一个管理人员招聘完成！" << endl;
	}

	void ShowAdministrator() 
	{ 
		cout << ano << "  " << name << "  " << gender << "  " << age << "  " << section << endl;
	}


	void ManageStudent(vector<Student>& studentList)
	{
		cout << "管理员 " << name << " 正在进行学生学籍管理..." << endl;

		
		Student newStudent("魏旭建", "男", 20, 3001, "人工智能");
		studentList.push_back(newStudent);

		// 示例：查询学生信息
		cout << "查询学生信息：" << endl;
		for ( Student& student : studentList) 
		{
			student.ShowStudent();
		}

	}

	void ArrangeCourse(vector<Teacher>&teacherList, vector<Student>&studentList) 
	{
			cout << "管理员 " << name << " 正在进行教师课程管理..." << endl;

			Teacher& teacher = teacherList[0]; // 假设选择第一个教师
			teacher.Course("深度学习和神经网络", "人工智能核心专业课", studentList);

			// 示例：查询课程信息
			cout << "查询课程信息：" << endl;
			for ( Teacher& teacher : teacherList) 
			{
				teacher.ShowTeacher();
			}
	}
};











class University 
{
	string uname, uaddress;  Student s[SNUM];	Teacher t[TNUM];	Administrator a[ANUM];
	int currentTerm;  // 用于跟踪当前学期

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
		cout << "学校 " << uname << " 第 " << currentTerm << " 学期开始注册管理..." << endl;

		ad.ManageStudent(studentList);
		ad.ArrangeCourse(teacherList, studentList);
		// 更新当前学期
		currentTerm++;
		cout << "第 " << currentTerm << " 学期注册管理结束。" << endl;
	}


	void ShowUniversity()
	{
		cout << "学校名称：" << uname << endl;
		cout << "学校地址：" << uaddress << endl;

		cout << "学生信息：" << endl;
		for (int i = 0; i < SNUM; i++) {
			s[i].ShowStudent();
		}

		cout << "教师信息：" << endl;
		for (int i = 0; i < TNUM; i++) {
			t[i].ShowTeacher();
		}

		cout << "管理人员信息：" << endl;
		for (int i = 0; i < ANUM; i++) {
			a[i].ShowAdministrator();
		}
	}
};

