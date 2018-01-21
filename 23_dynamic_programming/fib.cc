// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int memo[100];


int fib(int n){
    if (n == 0 || n == 1) return n;

    if (memo[n] != -1){
        // hey! I have the answer...so lets not compute it
        return memo[n];
    }

    int ans = fib(n - 1) + fib(n - 2);
    // registering in proces....
    memo[n] = ans;
    return ans;
}


int main(){
    int n;
    cin >> n;
    
    // initially memopad SHOULD be clean
    for(int i = 0; i <= n; ++i) memo[i] = -1;

    int ans = fib(n);
    cout << ans;   
}