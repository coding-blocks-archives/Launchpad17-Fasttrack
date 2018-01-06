// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void inputQue(queue<int>& q){
    int x;
    while(true){
        cin >> x;
        if (x == -1) break;

        q.push(x);
    }
}

void reverseQue(queue<int>& q){
    //T(N), S(N)
    stack<int> s;

    while(q.empty() == false){
        int frontElement = q.front();
        q.pop();
        s.push(frontElement);
    }

    // stack-->queue
    while(s.empty() == false){
        int topElement = s.top();
        s.pop();
        q.push(topElement);
    }
}


void printQue(queue<int>& q){
    while(q.empty() == false){
        cout << q.front() << " ";
        q.pop();
    }
}

int main(){
    queue<int> q;
    inputQue(q);
    reverseQue(q);
    printQue(q);    
}