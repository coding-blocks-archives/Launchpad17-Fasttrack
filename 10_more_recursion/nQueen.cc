// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

char board[10][10] = {};
const int DIM = 10;

void printBoard(int n, int m) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c  < n; ++c) {
            cout << board[r][c];
        }
        cout << endl;
    }
}

void setBoard(int n){
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c  < n; ++c) {
            board[r][c] = 'X';
        }
    }
}

bool check(char mat[DIM][DIM], int r, int c, int n) {

    // check for row and col
    for (int i = 0; i < n; ++i) {
        if (mat[r][i] == 'Q') return false;
        if (mat[i][c] == 'Q') return false;
    }

    // check for diagonal
    int rowDir[] = { -1, +1, -1, +1};
    int colDir[] = { -1, +1, +1, -1};

    for (int d = 0; d < n; ++d) {
        for (int i = 0; i < 4; ++i) {
            int curCellRow = r + rowDir[i] * d;
            int curCellCol = c + colDir[i] * d;

            if (curCellRow >= 0 && curCellRow < n &&
                    curCellCol >= 0 && curCellCol < n &&
                    mat[curCellRow][curCellCol] == 'Q') {
                return false;
            }
        }
    }
    return true;
}

bool nqueen(int n, int curRow) {
    // n = dimension of board
    // curRow in which I should start placing the queen
    // cuRow represents the no of queens placed so far
    if (n == curRow) {
        return true;
    }

    for (int c = 0; c < n; ++c) {
        bool isPossible = check(board, curRow, c, n);
        if (isPossible == true) {
            board[curRow][c] = 'Q';

            bool remBoard = nqueen(n, curRow + 1);
            if (remBoard == true) {
                return true;
            } else {
                board[curRow][c] = 'X';
            }
        }
    }
    return false;
}



int main() {
    int n;
    cin >> n;

    setBoard(n);
    bool ans = nqueen(n, 0);
    if (ans == true) {
        printBoard(n, n);
    }
    else {
        cout << "Sorry man! Can't place";
    }
}