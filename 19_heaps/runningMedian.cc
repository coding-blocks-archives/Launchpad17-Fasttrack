// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    while (true) {
        char choice;
        cin >> choice;
        switch (choice) {
        case '1':
            int d;
            cin >> d;
            add(d);
            printMedian();
            break;
        case '2':
            deleteMedian();
            printMedian();
            break;
        case '3': exit;
        }
    }
}