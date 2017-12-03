#include <iostream>
using namespace std;

int main(){
    double fahr;
    cin >> fahr;
    double cel = ((double)5 / 9) * (fahr - 32);
    cout << cel;
}