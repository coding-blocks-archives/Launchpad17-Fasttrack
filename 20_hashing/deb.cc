// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void foo(int x){
    for(int i = 0; i < x; ++i){
        cout << "Line 8 " << i << endl;
    }
    cout << "You have come out of loop. Current line is 10" << endl;
}

int main(){
    int x[10];
    cin >> x[1];
    foo(x[1]);   
    cout << "You have come out of foo. Now line 16" << endl;
    cout << "This is line 17" << endl;
}