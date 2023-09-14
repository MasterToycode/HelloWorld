#include <iostream>
#include <vector>
using namespace std;
const int N = 8; // ���̴�С
int totalSolutions = 0; // ���ڼ����������
// ��鵱ǰλ���Ƿ���Է��ûʺ�
bool isSafe(vector<vector<int>>& board, int row, int col) {
    // ��������Ƿ��Ѿ��лʺ�
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    // ������϶Խ����Ƿ��лʺ�
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    // ������϶Խ����Ƿ��лʺ�
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

// �ݹ����˻ʺ�����
//�����㷨
void solveNQueens(vector<vector<int>>& board, int row) {
    if (row == N) {
        // ���лʺ󶼳ɹ����ã���ӡ�Ⲣ���Ӽ���
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
            // �����ǰλ�ÿ��Է��ûʺ�����ûʺ󲢼�����һ��
            board[row][col] = 1;
            solveNQueens(board, row + 1);
            // ���ݵ���ǰ�У���������λ��
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