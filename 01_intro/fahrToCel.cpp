// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <iostream>
using namespace std;
int main() {
    int initial = 0;
    int final = 0;
    int step = 0;

    cin >> initial >> final >> step;

    int curTemp = initial;
    while(curTemp <= final){
        double cel = (5.0/9.0) * (curTemp - 32);
        cout << curTemp << "\t" << cel << endl;
        curTemp = curTemp + step; 
    }   
}