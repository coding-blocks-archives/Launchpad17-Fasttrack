// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;


void input(char mat[][20], int N){
    for(int i = 0; i < N; ++i){
        cin >> mat[i];  // mat[i] is an array of char....hence a word
    }
}

void output(char mat[][20], int N){
    for(int i = 0; i < N; ++i){
        cout << mat[i] << " ";
    }
    cout << endl;
}


void copyStr(char x[], char y[]) {
    int i = 0;
    while (y[i] != '\0') {
        x[i] = y[i];
        ++i;
    }
    x[i] = '\0';
}


void swapWords(char a[], char b[]) {
    char tmp[20];
    copyStr(tmp, b);    // tmp = b
    copyStr(b, a);      // b = a
    copyStr(a, tmp);    // a = tmp
}

bool isLargest(char x[], char y[]){
    int i = 0;
    // int j = 0;

    while(x[i] != '\0' && y[i] != '\0'){
        if (x[i] == y[i]){
            i++;    
            continue;
        }else if (x[i] > y[i]) {
            return true;
        }else {
            return false;
        }
    }
    if (x[i] == '\0') return false;
    return true;
}

int findLast(char words[][20], int be, int en) {
    // find the word that should come in the last
    char largest[20] = {};
    int largestPos = -1;

    while (be <= en) {
        if (isLargest(words[be], largest)) {
            // is words at be idx greater than largest?
            largestPos = be;
            copyStr(largest, words[be]);
        }
        ++be;
    }
    return largestPos;
}


void sortWords(char words[][20], int N) {
    // find last word and swap with the word at the endPos

    for (int i = 0; i < N; ++i) {
        int endPos = N - i - 1;

        // last words && pos at which the last word is present
        int pos = findLast(words, 0, endPos);
        swapWords(words[pos], words[endPos]);
    }
}

int main() {
    char words[30][20];
    int N;
    cin >> N;

    input(words, N);

    sortWords(words, N);

    output(words, N);
}