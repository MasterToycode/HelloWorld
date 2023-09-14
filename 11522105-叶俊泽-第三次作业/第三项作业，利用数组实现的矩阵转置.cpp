#include <iostream>
#include <iomanip> // ���������ʽ���ƵĿ�
using namespace std;

void rotate90DegreesClockwise(int**& M, int& n1, int& n2)
{
    int** temp = new int* [n2]; // ������ʱ��ά����
    for (int i = 0; i < n2; i++)
    {
        temp[i] = new int[n1];
    }

    // ˳ʱ����ת����
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            temp[j][n1 - i - 1] = M[i][j];
        }
    }

    // �ͷ�ԭ�����ڴ�
    for (int i = 0; i < n1; i++)
    {
        delete[] M[i];
    }
    delete[] M;

    // �����������;���ָ��
    swap(n1, n2);
    M = temp;
}

void fun2(int**& M, int n1, int n2, int angle) // n1,n2Ϊ�����������������MΪָ������ָ�룬angleΪ��ת�Ƕ�
{
    if (angle % 90 != 0 || angle < 0 || angle >= 360) // ���Ƕ��Ƿ���90�ı���������Ч��Χ��
    {
        cout << "��ת�Ƕȱ�����90�ȵı�������0��360��֮�䡣" << endl;
        return;
    }

    int rotations = angle / 90; // ������Ҫ��ת�Ĵ���

    while (rotations > 0)
    {
        rotate90DegreesClockwise(M, n1, n2);
        rotations--;
    }

    // ��ӡ��ת��ľ���
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout << setw(3) << M[i][j] << right; // �����ʽ���ƣ�ÿ��Ԫ��ռ3���ַ���ȣ��Ҷ���
        }
        cout << endl; // ÿ�����һ�оͻ���
    }
}

void fun1(int n1, int n2)
{
    cout << "Please input the elements of the Matrix:"; // ��ʾ�û��������Ԫ��
    int** M = new int* [n1]; // ��̬�����ά���飬���ڴ�ž���Ԫ��
    for (int i = 0; i < n1; i++)
    {
        M[i] = new int[n2]; // Ϊÿһ�з����ڴ�
        for (int j = 0; j < n2; j++) // �������飬����Ԫ��
        {
            int temp;
            cin >> temp;
            M[i][j] = temp;
            cout << setw(3) << M[i][j] << right; // �����ʽ���ƣ�ÿ��Ԫ��ռ3���ַ���ȣ��Ҷ���
        }
        cout << endl; // ÿ�����һ�оͻ���
    }

    int angle;
    cout << "��������ת�Ƕȣ�������90�ȵı�������"; // ��ʾ�û�������ת�Ƕ�
    cin >> angle;
    fun2(M, n1, n2, angle); // ����fun2�������Ծ��������ת
    for (int i = 0; i < n1; i++) // �ͷŷ�����ڴ�
    {
        delete[] M[i];
    }
    delete[] M;
}

int main()
{
    int n1, n2;
    cout << "Please input the dimension of the Matrix:"; // ��ʾ�û�������������������
    cin >> n1 >> n2;
    cout << endl;
    fun1(n1, n2); // ����fun1�������������Ԫ�ز�������ת
    return 0;
}
