// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

//====== DEVeloper ===
class Stack {
    struct Node {
    public:
        int data;
        Node* next;
        Node(int d){
            data = d;
            next = NULL;
        }
    };

    // data members
    Node* topPtr;
    int sze;

public:
    // ctor
    Stack() {
        topPtr = NULL;
        sze = 0;
    }

    // push(2)
    void push(int d) {
        Node* cur = new Node(d);
        ++sze;

        if (topPtr == NULL) {
            topPtr = cur;
            return;
        }

        cur->next = topPtr;
        topPtr = cur;
    }

    // top() ==> 2
    int top() {
        if (empty()) return -1;

        return topPtr->data;
    }

    // pop() ==> deletes an element
    void pop() {
        if (empty()) return;

        Node* tmp = topPtr;
        topPtr = topPtr->next;
        --sze;
        delete tmp;

    }

    // dtor ???
    ~Stack() {
        cout << "stack dtor" << endl;
        while (empty() == false) {
            pop();
        }
    }


    // empty() ==> yes/no
    bool empty() {
        return sze == 0;
    }
};

// ======== USER =========

void inputStack(Stack& s){
    int x;
    while(true){
        cin >> x;
        if (x == -1) break;

        s.push(x);
    }
}

void display(Stack& s){
    while(s.empty() == false){
        cout << s.top() << " ";
        s.pop();
    }
}

void moveStack(Stack& s1, Stack& s2){
    // moves elements of s2 into s1
    while(s2.empty() == false){
        s1.push(s2.top());
        s2.pop();
    }
}


// reverse
void reverseUsing2Stacks(Stack& s){
    Stack s1, s2;
    moveStack(s1, s);
    moveStack(s2, s1);
    moveStack(s, s2);

}

int main() {

    // Stack s;
    // cout << s.empty() << endl;
    // s.push(2);
    // s.push(3);
    // s.pop();
    // cout << s.top() << endl;
    // s.pop();
    // cout << s.top() << endl;
    // cout << s.top() << endl;

    Stack s;
    inputStack(s);

    reverseUsing2Stacks(s);

    display(s);

}