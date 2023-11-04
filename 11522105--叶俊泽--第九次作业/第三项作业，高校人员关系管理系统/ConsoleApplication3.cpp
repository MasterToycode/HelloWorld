#include"No3.h"
int main() 
{
    // 创建学生、教师和管理人员对象
    Student students[SNUM] = {
        Student("平原", "男", 20, 11522104, "人工智能"),
        Student("秦雅妮", "女", 19, 11522122, "人工智能")
    };

    Teacher teachers[TNUM] =
    {
        Teacher("陆明洲", "男", 35, 2001, "人工智能学院"),
        Teacher("陈朝霞", "女", 40, 2002, "人工智能学院")
    };

    Administrator administrators[ANUM] = 
    {
        Administrator("李洪", "男", 30, 3001, "教务处"),
        Administrator("于佳琪", "女", 28, 3002, "学生事务处")
    };

    // 初始化大学系统
    University myUniversity("南京农业大学", "点将台路40号", students, teachers, administrators);

    // 显示大学信息
    myUniversity.ShowUniversity();

    // 创建一个学期管理对象
    Administrator& admin = administrators[0];
    vector<Student> studentList;
    Student student1 ("沈  涛","男", 20, 11522112, "人工智能");
    Student student2 ("翁夏晴", "女", 19, 11522123, "人工智能");
    studentList.push_back(student1);
    studentList.push_back(student2);
    vector<Teacher> teacherList;
    Teacher teacher1 ("任守纲", "男", 35, 2001, "人工智能学院");
    Teacher teacher2 ("梁昆", "女", 28, 3002, "学生事务处");
    teacherList.push_back(teacher1);
    teacherList.push_back(teacher2);
    // 第一个学期开始
    myUniversity.TermBegin(admin, studentList, teacherList);

    // 第二个学期开始
    myUniversity.TermBegin(admin, studentList, teacherList);

    return 0;
}