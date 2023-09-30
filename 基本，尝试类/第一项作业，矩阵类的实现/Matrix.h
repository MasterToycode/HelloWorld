#include<iostream>
#include<string>
#include <iomanip>
using namespace std;

class Matrix
{
    private:
        int n1, n2;
        int** M;
    public:
        // ���캯�����վ����ά����Ϊ����
        Matrix(int t1, int t2) : n1(t1), n2(t2)
        {
            M = nullptr; // ��ʼ��MΪnullptr
        }
        // �������������ͷŷ�����ڴ�
        ~Matrix()
        {
            if (M != nullptr)
            {
                for (int i = 0; i < n1; i++)
                {
                    delete[] M[i];
                }
                delete[] M;
            }
        }
    void InitializeMatrix();
    void OutPut();
    void Modify(int n1, int n2);
    void Multiply();
    void rotate90DegreesClockwise();
    void Rotate90DegreesClockwise();
};



// ��Ա�������ڷ�������ڴ���������Ԫ��
void Matrix::InitializeMatrix()
{
    cout << "Please input the elements of the Matrix:"; // ��ʾ�û��������Ԫ��
    M = new int* [n1]; // ��̬�����ά���飬���ڴ�ž���Ԫ��
    for (int i = 0; i < n1; i++)
    {
        M[i] = new int[n2]; // Ϊÿһ�з����ڴ�
        for (int j = 0; j < n2; j++) // �������飬����Ԫ��
        {
            cin >> M[i][j];
            cout << setw(3) << M[i][j] << right; // �����ʽ���ƣ�ÿ��Ԫ��ռ3���ַ���ȣ��Ҷ���
        }
        cout << endl; // ÿ�����һ�оͻ���
    }
}



void Matrix::OutPut()
{
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout << setw(3) << M[i][j] << right; // �����ʽ���ƣ�ÿ��Ԫ��ռ3���ַ���ȣ��Ҷ���
        }
        cout << endl; // ÿ�����һ�оͻ���
    }
}

void Matrix::Multiply()
{
    cout << "Please input the number that the Matrix will multipy:"; //��ʾ�û��������
    int number;
    cin >> number;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            M[i][j] *= number;
            cout << setw(3) << M[i][j] << right; // �����ʽ���ƣ�ÿ��Ԫ��ռ3���ַ���ȣ��Ҷ���
        }
        cout << endl; // ÿ�����һ�оͻ���
    }
}

void Matrix::rotate90DegreesClockwise()
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

void Matrix::Rotate90DegreesClockwise()
{
    int angle;
    cout << "��������ת�Ƕȣ�������90�ȵı�������"; // ��ʾ�û�������ת�Ƕ�
    cin >> angle;
    while (1) {
        if (angle % 90 != 0 || angle < 0 || angle >= 360) // ���Ƕ��Ƿ���90�ı���������Ч��Χ��
        {
            cout << "��ת�Ƕȱ�����90�ȵı�������0��360��֮�䡣����������:";
            cin >> angle;
            cout << endl;
        }
        else break;
    }
    int rotations = angle / 90; // ������Ҫ��ת�Ĵ���

    while (rotations > 0)
    {
        Matrix::rotate90DegreesClockwise();
        rotations--;
    }
}

