#include <iostream>
using namespace std;
// 定义递归函数，实现汉诺塔移动的过程
void hanoi(int n, char source, char auxiliary, char target) {
    // 如果只有一个盘子，直接将其从源杆移动到目标杆
    if (n == 1) {
        cout << "移动盘子 " << n << " 从 " << source << " 到 " << target << std::endl;
        return;
    }
    // 将 n-1 个盘子从源杆移动到辅助杆
    hanoi(n - 1, source, target, auxiliary);
    // 将第 n 个盘子从源杆移动到目标杆
    cout << "移动盘子 " << n << " 从 " << source << " 到 " << target << std::endl;
    // 将 n-1 个盘子从辅助杆移动到目标杆
    hanoi(n - 1, auxiliary, source, target);
}

int main() {
    int n;
    cout << "请输入盘子的数量：";
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
