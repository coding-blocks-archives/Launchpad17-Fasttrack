// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printInc(int n){
    // prints the n numbers in inc order
    // <space> number

    if (n <= 0) return ;

    printInc(n - 1);
    cout << " ";
    cout << n;
}

int main(){
    int n;
    cin >> n;
    printInc(n);   
}