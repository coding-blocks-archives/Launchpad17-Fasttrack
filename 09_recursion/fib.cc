// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int fib(int n){
    // fib(n) gives the nth fib no

    // base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // recurrence
    int nMinusOne = fib(n - 1);     //recursion
    int nMinusTwo = fib(n - 2);

    int cur = nMinusOne + nMinusTwo;
    return cur;

    // int cur = fib(n - 1) + fib (n - 2);
    // return cur;

}

int main(){
    int N;
    cin >> N;

    int ans = fib(N);
    cout << ans;   
}