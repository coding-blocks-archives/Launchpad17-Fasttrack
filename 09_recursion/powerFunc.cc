// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int power(int x, int p){
    // returns x^p; p cannot be negative
    if (p == 0) return 1;   // base case

    int smallerPower = power(x, p - 1); // recurrence
    int ans = smallerPower * x;
    return ans; 
}

int main(){
    int x, p;
    cin >> x >> p;

    int ans = power(x, p);
    cout << ans;   
}