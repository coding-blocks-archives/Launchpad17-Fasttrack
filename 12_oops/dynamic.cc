// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int* foo() {
    int y = 2;
    int * ptr = &y;
    cout << "ptr " << ptr << endl;
    return ptr;
}


int * dynamicAlloc() {
    int * ptr = new int;
    *ptr = 2;
    return ptr;
}

int main() {
    int x = 2;

    // int * ans = foo();

    int * ans = dynamicAlloc();

    cout << "add of fun " << (int*)foo << endl;
    
    cout << "add of fun " << (int*)dynamicAlloc << endl;

    cout << "ans " << ans << endl;
    cout << "*ans " << *ans << endl;

    delete ans;
    cout << "*ans " << *ans << endl;

    cout << "x " << x << endl;


}