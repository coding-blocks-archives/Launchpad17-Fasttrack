// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <iomanip>
using namespace std;

double squareRoot(int n, int prec) {
    double root = 0;
    double inc = 1;

    for (int p = 0; p <= prec; ++p) {
        while (root * root <= n) {
            root = root + inc;
        }
        root -= inc;
        inc = inc / 10;
    }

    return root;
}


int main() {
    int n, p;
    cin >> n >> p;
    cout << fixed << setprecision(5) << squareRoot(n, p);
    
}