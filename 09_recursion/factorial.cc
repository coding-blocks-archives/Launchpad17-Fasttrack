// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int factorial(int n){
    // factorial(n) calculates the factorial of number n and return it
    if (n <= 0) return 1;

    int nMinusOne = factorial(n - 1);
    int ans = n * nMinusOne;
    return ans;
}



int main(){
    int N;
    cin >> N;
        
    int nfact = factorial(N);
    cout << nfact;

}