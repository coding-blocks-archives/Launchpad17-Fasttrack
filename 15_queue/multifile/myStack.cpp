#include "myStack.h"
#include <iostream>
using namespace std;

Stack::Node::Node(int d) {
    data = d;
    next = NULL;
}

Stack::Stack() {
    topPtr = NULL;
    sze = 0;
}


void Stack::push(int d) {
    Node* cur = new Node(d);
    ++sze;

    if (topPtr == NULL) {
        topPtr = cur;
        return;
    }

    cur->next = topPtr;
    topPtr = cur;
}

int Stack::top() {
    if (empty()) return -1;

    return topPtr->data;
}

void Stack::pop() {
    if (empty()) return;

    Node* tmp = topPtr;
    topPtr = topPtr->next;
    --sze;
    delete tmp;

}

Stack::~Stack() {
    cout << "stack dtor" << endl;
    while (empty() == false) {
        pop();
    }
}

bool Stack::empty() {
    return sze == 0;
}