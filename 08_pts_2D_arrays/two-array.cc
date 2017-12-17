// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int mat[2][3] = {};

    int *ptr = mat[0];
    int (*p)[3] = &mat[0];

    int (*pm)[2][3] = &mat;

    cout << *ptr << endl;
    cout << *p << endl;


}