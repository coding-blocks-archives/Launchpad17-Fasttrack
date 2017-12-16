// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void InputMatrix(int arr[10][10], int nRows, int nCols){
  for(int r = 0; r < nRows; ++r){
    for(int c = 0; c < nCols; ++c){
      cin >> arr[r][c];
    }
  }
}

void OutputMatrix(int arr[10][10], int nRows, int nCols){
  // Start writing below this line...

  cout << "--------------\n";

  for(int r = 0; r < nRows; ++r){
    for(int c = 0; c < nCols; ++c){
      cout << arr[r][c] << " ";
    } 
    cout << endl;
  }
  
  cout << "--------------\n";
}

// find largest row
void LargestRow(int mat[][10], int nRows, int nCols){
  const int inf = 1000000;
  int maxSum = -inf;
  int maxRow = -1;

  // check
  for(int r = 0; r < nRows; ++r){
    int curSum = 0; // for every row, curSum HAS to be zero
    for(int c = 0; c < nCols; ++c){
      curSum = curSum + mat[r][c];
    }

    // curSum now contains sum of the CURRENT "ROW"
    // check if it could be largest
    if (curSum > maxSum){
      maxSum = curSum;
      maxRow = r;
    }
  }

  cout << "Largest Row is " << maxRow << " with sum = " << maxSum << endl;  

}

// find largest col
void LargestCol(int mat[][10], int nRows, int nCols){
  // Most significant dimension is optional
  // Rest all are mandatory

  const int inf = 1e5;  // scientific notation 1 x 10^5
  int maxSum = -inf;
  int maxCol = -1;

  for(int c = 0; c < nCols; ++c){
    int curSum = 0;

    // iterate every row
    for(int r = 0; r < nRows; ++r){
      // curSum = curSum + mat[r][c];
      curSum += mat[r][c];    // compound statement
    }

    if (curSum > maxSum){
      maxSum = curSum;
      maxCol = c;
    }
  }

  cout << "Max col is " << maxCol << " with sum " << maxSum << endl;
}



// largest Row Col
void LargestRowCol(int mat[][10], int nRows, int nCols) {
  // single traversal
  // O(N2)

  int colSum[10] = {};  // all zero
  int maxRow = -1;
  int maxRowSum = -(1e6);

  for (int r = 0; r < nRows; ++r) {
    int curRowSum = 0;
    for (int c = 0; c < nCols; ++c) {
      curRowSum += mat[r][c];

      // setting the current element to its corresponding col sum
      colSum[c] += mat[r][c];

    }
    if (curRowSum > maxRowSum) {
      maxRowSum = curRowSum;
      maxRow = r;
    }
  }
  // colSum contains all column Sums
  // maxRowSum contains the sum correspoding to largest row

  int maxColSum = -(1e6);
  int maxCol = -1;
  for (int c = 0; c < nCols; ++c) {
    if (maxColSum < colSum[c]) {
      maxColSum = colSum[c];
      maxCol = c;
    }
  }

  // printing
  cout << "Row " << maxRowSum << " " << maxRow << endl;
  cout << "Col " << maxColSum << " " << maxCol << endl;

}

int main(){
  int mat[10][10];

  int M, N;
  cin >> M >> N;

  InputMatrix(mat, M, N);
  OutputMatrix(mat, M, N);

  // LargestRow(mat, M, N);
  // LargestCol(mat, M, N); 

  LargestRowCol(mat, M, N);

  return 0; // 0 means successful termination 
}