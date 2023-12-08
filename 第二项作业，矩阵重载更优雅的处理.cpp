#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;
class Matrix {
private:
    int m;  // ����
    int n;  // ����
    vector<vector<int>> data;  // ��������

public:
    // ���캯��
    Matrix(int rows, int cols) : m(rows), n(cols), data(rows, vector<int>(cols, 0)) {}

    // ���ؼӷ������
    Matrix operator+(const Matrix& other) const {
        Matrix result(m, n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    // ���ؼ��������
    Matrix operator-(const Matrix& other) const {
        Matrix result(m, n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    // ���س˷������
    Matrix operator*(const Matrix& other) const {
        // �������Ƿ��ܹ����
        if (n != other.m) {
            throw std::invalid_argument("�޷���ˣ���һ����������������ڵڶ��������������");
        }

        Matrix result(m, other.n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < other.n; ++j)
                for (int k = 0; k < n; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }


    // ���س��������
    Matrix operator/(const Matrix& other) const {
        // ����򻯴����������������û����Ԫ��
        Matrix result(m, n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                result.data[i][j] = data[i][j] / other.data[i][j];
        return result;
    }

    void inputMatrix() {
        cout << "����������Ԫ��ֵ��" << std::endl;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                cout << "�������" << i + 1 << "�У���" << j + 1 << "�е�Ԫ�أ�";
                cin >> data[i][j];
            }
    }


    // �����������
    void display() const {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};
int main() {
    // �û���������С
    int m, n;
    cout << "����������������������" << endl;
    cin >> m >> n;

    // ���������������
    Matrix a(m, n);
    Matrix b(m, n);

    // �û��������Ԫ��ֵ
    a.inputMatrix();
    b.inputMatrix();

    // ���ԼӼ��˳�����
    Matrix c = a + b;
    cout << "����A + ����B��" << endl;
    c.display();

    c = a - b;
    cout << "����A - ����B��" << endl;
    c.display();

    c = a / b;
    cout << "����A / ����B��" << endl;
    c.display();

    try
    {
        c = a * b;
        cout << "����A * ����B��" << endl;
        c.display();
    }

    catch (const invalid_argument& e)
    {
        // ��׽�쳣�������ϸ������Ϣ
        cerr << "����" << e.what() << endl;
    }

    return 0;
}
