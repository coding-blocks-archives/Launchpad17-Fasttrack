// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int x = 5;
    int y = 3;
    int z = 10;


    // if (x == 2) cout << x;
    // else if (x == 3) cout << y;
    // else if (x == 5) cout << z;
    // else cout << "codingblocks";

    switch(x){
        case 2 : 
            cout << x; // has to be a compile time constant
            break;
        case 3 : cout << y;
        case 5 : cout << z; break;
        default : cout << "codingblocks";
    }

}