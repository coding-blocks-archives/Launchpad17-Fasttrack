// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;

void symToStr(char sym, char arr[]) {
    char digToChar[][10] = {  // array of words
        " ",       // '0'
        "!@#", "abc", "def", // '1', '2', '3'
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"

    };

    int i = sym - '0';
    strcpy(arr, digToChar[i]);
}

void printKeypad(char num[], int be, char decision[], int i) {
    if (num[be] == '\0'){
        decision[i] = '\0';
        cout << decision << endl;
        return;
    }


    char curButton[10];
    symToStr(num[be], curButton);

    for (int j = 0; curButton[j] != '\0'; ++j) {
        decision[i] = curButton[j];
        printKeypad(num, be + 1, decision , i + 1);
    }
}

int main() {
    char num[10];
    cin >> num;
    char decision[10];
    printKeypad(num, 0, decision, 0);

}