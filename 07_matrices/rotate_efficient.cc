// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;

void RotateArray(char arr[], int k){
  int len = strlen(arr);
  int n = k % len;

  // copy last n char into tmp
  int curPos = 0;
  char tmp[100];
  
  for(int i = len - n; i < len; ++i){
    tmp[curPos] = arr[i];
    ++curPos;
  }

  // shift remaining char in the end
  curPos = len - 1;
  for(int i = len - n - 1; i >= 0; --i){
    arr[curPos] = arr[i];
    --curPos;
  }

  // copy last n char that have been copied into tmp to the
  // original array
  for(int i = 0; i < n; ++i){
    arr[i] = tmp[i];
  }
}


int main(){
  char arr[100];
  cin >> arr;

  int k;
  cin >> k;

  RotateArray(arr, k);

  cout << arr;  
}