#include"No.1.h"
int main() {
    // 创建 CDeriveA 对象
    CDeriveA derivedA(1, 2, 3, 4, 5, 6);
    cout << "CDeriveA:" << endl;

    //derivedA.showax();
    //derivedA.showay();
    //都不能直接访问！

    derivedA.showaz();
    derivedA.outshow(); // 测试访问基类的保护和公有成员
    cout << endl;

    // 创建 CDeriveB 对象
    CDeriveB derivedB(7, 8, 9, 10, 11, 12);
    cout << "CDeriveB:" << endl;

    //derivedB.showbx();
    //derivedB.showby();
     //都不能直接访问！

    derivedB.showbz();
    derivedB.outshow(); // 测试访问基类的保护和公有成员
    cout << endl;

    // 创建 CDeriveC 对象
    CDeriveC derivedC(13,14,15,16,17,18);
    cout << "CDeriveC:" << endl;

    //derivedC.showcx();
    //derivedC.showcy();
    //都不能直接访问！

    derivedC.showcz();
    derivedC.showCxandBasexfromOuterC(); // 测试访问基类的保护成员
    derivedC.showCyandBaseyfromOuterC(); // 测试访问基类的公有成员


    cout << "无论采用哪种继承方式（私有、保护或公有继承），" << endl
        << "派生类都不能直接在自己的成员函数或数据中访问基类的私有成员。" << endl
        << "私有成员对于派生类来说是不可见的，只有基类的成员函数可以访问它们。" << endl
        << "派生类只能通过基类提供的公有接口（公有和受保护成员）来间接访问基类的私有成员" << endl;
    return 0;
}
