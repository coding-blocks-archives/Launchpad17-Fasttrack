// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
#include <iomanip>
#include <functional>
using namespace std;

class compare {
public:
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};

typedef priority_queue<int> maxheap;    // maxheap
// typedef priority_queue<int, vector<int>, compare> minHeap;  // minHeap
typedef priority_queue<int, vector<int>, greater<int> > minHeap;  // minHeap

void rebalance(maxheap& leftHeap, minHeap& rightHeap) {
    if (leftHeap.size() < rightHeap.size()) {
        int x = rightHeap.top();
        rightHeap.pop();
        leftHeap.push(x);
    } else if (leftHeap.size() - rightHeap.size() > 1) {
        rightHeap.push(leftHeap.top());
        leftHeap.pop();
    }
}

void add(maxheap& leftHeap, minHeap& rightHeap, int x) {
    if (leftHeap.empty() || x <= leftHeap.top()) {
        leftHeap.push(x);
    } else {
        rightHeap.push(x);
    }

    rebalance(leftHeap, rightHeap);
}

double median(maxheap& leftHeap, minHeap& rightHeap) {
    if (rightHeap.empty() || leftHeap.size() > rightHeap.size()) {
        return leftHeap.top();
    }
    return (leftHeap.top() + rightHeap.top()) / 2.0;
}


int main() {
    maxheap leftHeap;
    minHeap rightHeap;
    int x;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        // add
        cin >> x;
        add(leftHeap, rightHeap, x);

        cout << setprecision(1) << fixed << median(leftHeap, rightHeap) << endl;
        // sticky

        // median print
    }

    return 0;   // successful termination
}