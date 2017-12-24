// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void mySwap(int &x, int &y){ // called parameters
    //parameters
    int t = x;
    x = y;
    y = t;
}

int main(){
    int a = 2;
    int b = 3;

    mySwap(a, b);       // calling parameters, arguments

    cout << a << " " << b;   
}