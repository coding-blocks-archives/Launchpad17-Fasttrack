// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printCharEquv(char num[], int be, char decision[], int i){
    if (num[be] == '\0'){
        decision[i] = '\0';
        cout << decision << endl;
        return;
    }


    char curSymbol = num[be];
    int curDig = curSymbol - '0';  // '1' - '0' = 1 
    char curChar = 'a' + curDig - 1; 
    
    decision[i] = curChar;
    printCharEquv(num, be + 1, decision, i + 1);

    // 2 wale 
    if (num[be + 1] == '\0') return ;

    char nextSymbol = num[be + 1];
    int nextDig = nextSymbol - '0';
    int cur2DigNum = curDig * 10 + nextDig;
    if (cur2DigNum > 26) return;
    char char2Dig = 'a' + cur2DigNum - 1;
    decision[i] = char2Dig;
    printCharEquv(num, be + 2, decision, i + 1);

    // 'a' + 1 = 'b'    // 'a'  + 2 = c 

}

int main(){
    char num[100];
    char decision[100];

    cin >> num;

    printCharEquv(num, 0, decision, 0);   
}