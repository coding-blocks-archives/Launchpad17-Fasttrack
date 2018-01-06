// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
using namespace std;

class specialStack {
    queue<int> q;

    void shift(){
        int nTimes = q.size() - 1;
        for(int i = 0; i < nTimes;  ++i){
            int cur = q.front();
            q.pop();
            q.push(cur);
        }
    }
public:
    void push(int d) {
        q.push(d);
    }

    int pop() {
        
        shift();
        q.pop();
    }

    int top(){
        shift();
        int ans =  q.front();
        q.push(ans);
        q.pop();
        return ans;

    }
};


// =====USER====
int main() {
    specialStack s;
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

}