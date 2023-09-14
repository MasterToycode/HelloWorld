#include <iostream>
#include <vector>
using namespace std;
const int N = 8; // 棋盘大小
int totalSolutions = 0; // 用于计数解的数量
// 检查当前位置是否可以放置皇后
bool isSafe(vector<vector<int>>& board, int row, int col) {
    // 检查列上是否已经有皇后
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    // 检查左上对角线是否有皇后
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    // 检查右上对角线是否有皇后
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

// 递归解决八皇后问题
//回溯算法
void solveNQueens(vector<vector<int>>& board, int row) {
    if (row == N) {
        // 所有皇后都成功放置，打印解并增加计数
        ++totalSolutions;
        cout << "Solution " << totalSolutions << ":\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col)) {
            // 如果当前位置可以放置皇后，则放置皇后并继续下一行
            board[row][col] = 1;
            solveNQueens(board, row + 1);
            // 回溯到当前行，尝试其他位置
            board[row][col] = 0;
        }
    }
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, 0));
    solveNQueens(board, 0);
    cout << "Total solutions is : " << totalSolutions << endl;
    return 0;
}