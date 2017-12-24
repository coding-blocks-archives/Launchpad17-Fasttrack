// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void updateX(int &t){
    ++t;
}

int main(){
    int x = 2;

    updateX(x);

    cout << x;   
}