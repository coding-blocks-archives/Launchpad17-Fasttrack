// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class comparator{
public:
    bool operator()(int a, int b){
        return a > b;
    }
};

int main(){
    
    // priority_queue<int, vector<int>, comparator> q;
    priority_queue<int> q;
    q.push(3);
    q.push(4);
    cout << q.top();

}