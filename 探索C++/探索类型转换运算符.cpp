#include<iostream>
#include <iomanip>
using namespace std;
class RMB
{
protected:    unsigned int yuan, jf;
public:
    RMB(double v = 0.0)
    {
        yuan = unsigned(v);
        jf = unsigned((v - yuan) * 100.0 + 0.5);
    }

    operator double() { return yuan + jf / 100.0; }

    friend ostream& operator<<(ostream& output, RMB& d);

};



ostream& operator<<(ostream& output, RMB& d)
{
    output << d.yuan << '.' << setfill('0') << setw(2) << d.jf << setfill(' ');
    return output;
}


int main()
{
    RMB rmb(2.3);
    cout << "Initially rmb = " << rmb << endl;
    rmb = 2.0 * rmb;// ����һ�У�����2.0��double���ͣ�������operator double()�ĵ���
    cout << "then rmb = " << rmb << endl;
}



