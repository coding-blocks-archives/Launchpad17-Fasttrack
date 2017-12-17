// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void foo(int arr[]) {
    cout << arr << endl;
    cout << sizeof(arr) << endl;
}

int main() {
    int x[10];

    cout << x << endl;
    cout << x + 1 << endl;
    cout << (&x) + 1 << endl;

    // int (*ptr)[10] = &x;
    // cout << sizeof(ptr) << endl;


    // cout << x << " " <<  sizeof(x) << endl;
    // foo(x);

}