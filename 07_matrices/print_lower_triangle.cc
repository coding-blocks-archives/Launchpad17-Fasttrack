// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void InputMatrix(int arr[10][10], int nRows, int nCols) {
  for (int r = 0; r < nRows; ++r) {
    for (int c = 0; c < nCols; ++c) {
      cin >> arr[r][c];
    }
  }
}

void OutputMatrix(int arr[10][10], int nRows, int nCols) {
  // Start writing below this line...

  cout << "--------------\n";

  for (int r = 0; r < nRows; ++r) {
    for (int c = 0; c < nCols; ++c) {
      cout << arr[r][c] << " ";
    }
    cout << endl;
  }

  cout << "--------------\n";
}

void printLowerTriangle(int mat[10][10], int nRows, int nCols) {

  for (int r = 0; r < nRows; ++r) {
    for (int c = 0; c <= r; ++c) {
      cout << mat[r][c] << " ";
    }
    cout << endl;
  }

}


int main() {
  int arr[10][10];

  int m, n;
  cin >> m >> n;

  // input
  InputMatrix(arr, m, n);

  // print
  OutputMatrix(arr, m, n);

  // print lower Diagonal
  printLowerTriangle(arr, m, n);

}