#include <iostream>
#include "myStack.h"
using namespace std;

void inputStack(Stack& s) {
    int x;
    while (true) {
        cin >> x;
        if (x == -1) break;

        s.push(x);
    }
}

void display(Stack& s) {
    while (s.empty() == false) {
        cout << s.top() << " ";
        s.pop();
    }
}

void moveStack(Stack& s1, Stack& s2) {
    // moves elements of s2 into s1
    while (s2.empty() == false) {
        s1.push(s2.top());
        s2.pop();
    }
}

// reverse
void reverseUsing2Stacks(Stack& s) {
    Stack s1, s2;
    moveStack(s1, s);
    moveStack(s2, s1);
    moveStack(s, s2);

}

bool isBalanced(char arr[]) {
    Stack s;

    for (int i = 0; arr[i] != '\0'; ++i) {
        if (arr[i] == '(') {
            s.push(arr[i]);
        }
        else if (arr[i] == ')') {
            if (s.empty()) return false;
            s.pop();
        }
    }

    return s.empty();
}

int main() {

    Stack s;
    // cout << s.empty() << endl;
    // s.push(2);
    // s.push(3);
    // s.pop();
    // cout << s.top() << endl;
    // s.pop();
    // cout << s.top() << endl;
    // cout << s.top() << endl;

    // Stack s;
    // inputStack(s);
    // reverseUsing2Stacks(s);
    // display(s);

    char arr[100];
    cin >> arr;

    bool ans = isBalanced(arr);
    cout << ans;

}