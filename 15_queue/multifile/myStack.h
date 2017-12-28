#ifndef STACK_H
#define STACK_H

class Stack {
    struct Node {
    public:
        int data;
        Node* next;
        Node(int d);
    };
    Node* topPtr;
    int sze;
public:
    Stack();
    void push(int d);
    int top();
    void pop() ;
    ~Stack();
    bool empty() ; 
};

#endif