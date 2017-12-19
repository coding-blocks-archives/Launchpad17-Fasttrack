// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printDec(int n){
    // print 5 4 3  2 1 
    if (n <= 0) return;

    cout << n << " ";
    printDec(n - 1);
}

int main(){
    int n;
    cin >> n;
    printDec(n);   
}