// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class Pen {
public:
    int brand;
    int price;
    int color;
    int charWrittenSoFar;

    Pen(int br, int pr, int col, int charsofar) {
        brand = br;
        price = pr;
        color = col;
        charWrittenSoFar = charsofar;
    }

    Pen(int br, int col, int charsofar) {
        brand = br;
        color = col;
        charWrittenSoFar = charsofar;
    }


    void write(char arr[]) {
        int len = strlen(arr);
        charWrittenSoFar += len;
    }
};

int main() {
    Pen trimax(10, 100, 10, 0);
    Pen parker(007, 1000, 000);

    // trimax.initialise(10, 100, 10, 0);
    // cello.initialise();

    // initialise(trimax, 10, 100, 10, 0);
    //stedllar, price, blue, charsofar


    char str[100];
    cin >> str;

    // write(trimax, str);
    trimax.write(str);
    cout << trimax.charWrittenSoFar << endl;

    cin >> str;
    // write(trimax, str);
    trimax.write(str);
    cout << trimax.charWrittenSoFar << endl;

}