#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;
class Matrix {
private:
    int m;  // 行数
    int n;  // 列数
    vector<vector<int>> data;  // 矩阵数据

public:
    // 构造函数
    Matrix(int rows, int cols) : m(rows), n(cols), data(rows, vector<int>(cols, 0)) {}

    // 重载加法运算符
    Matrix operator+(const Matrix& other) const {
        Matrix result(m, n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    // 重载减法运算符
    Matrix operator-(const Matrix& other) const {
        Matrix result(m, n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    // 重载乘法运算符
    Matrix operator*(const Matrix& other) const {
        // 检查矩阵是否能够相乘
        if (n != other.m) {
            throw std::invalid_argument("无法相乘：第一个矩阵的列数不等于第二个矩阵的行数。");
        }

        Matrix result(m, other.n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < other.n; ++j)
                for (int k = 0; k < n; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }


    // 重载除法运算符
    Matrix operator/(const Matrix& other) const {
        // 这里简化处理，假设除数矩阵中没有零元素
        Matrix result(m, n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                result.data[i][j] = data[i][j] / other.data[i][j];
        return result;
    }

    void inputMatrix() {
        cout << "请输入矩阵的元素值：" << std::endl;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                cout << "请输入第" << i + 1 << "行，第" << j + 1 << "列的元素：";
                cin >> data[i][j];
            }
    }


    // 输出矩阵内容
    void display() const {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};
int main() {
    // 用户输入矩阵大小
    int m, n;
    cout << "请输入矩阵的行数和列数：" << endl;
    cin >> m >> n;

    // 创建两个矩阵对象
    Matrix a(m, n);
    Matrix b(m, n);

    // 用户输入矩阵元素值
    a.inputMatrix();
    b.inputMatrix();

    // 测试加减乘除运算
    Matrix c = a + b;
    cout << "矩阵A + 矩阵B：" << endl;
    c.display();

    c = a - b;
    cout << "矩阵A - 矩阵B：" << endl;
    c.display();

    c = a / b;
    cout << "矩阵A / 矩阵B：" << endl;
    c.display();

    try
    {
        c = a * b;
        cout << "矩阵A * 矩阵B：" << endl;
        c.display();
    }

    catch (const invalid_argument& e)
    {
        // 捕捉异常，输出详细错误信息
        cerr << "错误：" << e.what() << endl;
    }

    return 0;
}
