// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;

void printSubSeq(char s[], int be, int en, char decision[], int i) {
    if (be == en) {
        decision[i] = '\0';
        cout  << decision  << endl;
        return;
    }

    // lets fix 'a'
    decision[i] = s[be];
    printSubSeq(s, be + 1, en, decision, i + 1);

    // lets ignore 'a'
    printSubSeq(s, be + 1, en, decision, i);

}

int main() {
    char str[100];
    cin >> str;

    int len = strlen(str);

    char decision[100] = "";

    printSubSeq(str, 0, len, decision, 0);
}