// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> v;
    int sze;

    int parent(int i) { return i / 2;}
    int left(int i) { return 2 * i; }
    int right(int i) { return 2 * i + 1; }

    void heapify(int i){

        // left child comparison
        int posOfLargest = i;
        if (left(i) <= sze && v[left(i)] > v[i]){
            posOfLargest = left(i);
        }

        if (right(i) <= sze && v[right(i)] > v[posOfLargest]){
            posOfLargest = right(i);
        }

        if (i != posOfLargest){
            // I HAVE to swap
            swap(v[i], v[posOfLargest]);
            heapify(posOfLargest);
        }
    }

public:
    Heap() {
        sze = 0;
        v.push_back(-1);    // empty position
    }

    int top() {
        if (empty()) return -1;
        return v[1];
    }

    bool empty() {
        return sze == 0;
    }

    void pop() {
        if (empty()) return;

        swap(v[1], v[sze]);
        v.pop_back();
        --sze;

        heapify(1);
    }

    void push(int d) {
        // push and compare with the parent
        v.push_back(d);
        ++sze;

        int i = v.size() - 1;
        while(i > 1 && v[i] > v[parent(i)]){
            swap(v[i], v[parent(i)]);
            i = parent(i);
        }
    }

    void print(){
        for(int i = 1; i <= sze; ++i){
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap H;
    H.push(2);
    H.print();
    H.push(30);
    H.print();
    H.push(32);
    H.print();
    H.push(-1);
    H.print();

    // cout << H.top(); H.pop();
    // cout << H.top(); H.pop();
    // cout << H.top(); H.pop();
    // cout << H.top(); H.pop();

}