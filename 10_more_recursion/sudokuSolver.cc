// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cmath>
using namespace std;

const int DIM = 10;
bool fixedMat[DIM][DIM] = {};

void printBoard(int board[DIM][DIM], int n) {
    for (int r = 0; r < n; ++r) {
        cout << "------------------\n";
        for (int c = 0; c  < n; ++c) {
            cout << board[r][c] << "|";
        }
        cout << endl;
    }
}

void setFixedCells(int board[DIM][DIM], int n) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c  < n; ++c) {
            if (board[r][c] != 0) {
                fixedMat[r][c] = true;
            } else {
                fixedMat[r][c] = false;
            }
        }
    }
}

bool check(int board[DIM][DIM], int r, int c, int n, int num) {
    for (int i = 0; i < n; ++i) {
        if (board[r][i] == num) return false;
        if (board[i][c] == num) return false;
    }

    // checking the BOX
    int rootN = sqrt(n);
    int startIdx = (r / rootN) * rootN;
    int startCol = (c / rootN) * rootN;
    for (int i = startIdx; i < startIdx + rootN; ++i) {
        for (int j = startCol; j < startCol + rootN; ++j) {
            if (board[i][j] == num) return false;
        }
    }

    // checked everything finally :)
    return true;
}


bool sudoku(int board[DIM][DIM], int r, int c, int n) {
    if (r == n) {
        return true;
    }

    if (c == n) {
        return sudoku(board, r + 1, 0, n);
    }

    if (fixedMat[r][c] == true) {
        return sudoku(board, r, c + 1, n);
    }

    for (int curNum = 1; curNum <= n; ++curNum) {
        bool canPlace = check(board, r, c, n, curNum);
        if (canPlace == true) {
            board[r][c] = curNum;
            bool remBoard = sudoku(board, r, c + 1, n);
            if (remBoard == true) {
                return true;
            } else {
                // the no that was placed must be removed
                board[r][c] = 0;
            }
        }
    }
    return false;

}


int main() {
    int board[DIM][DIM] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    int n = 9;

    setFixedCells(board, n);

    bool isSolvable = sudoku(board, 0, 0, n);
    if (isSolvable) {
        printBoard(board, n);
    } else {
        cout << "Can't solve";
    }

}