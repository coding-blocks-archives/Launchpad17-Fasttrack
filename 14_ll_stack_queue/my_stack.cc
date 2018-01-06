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
