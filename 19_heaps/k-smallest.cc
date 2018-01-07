// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
using namespace std;

void printBestK(int arr[], int n, int k){
    // smallest k
    priority_queue<int> q;  // maxHeap
    
    // push first k elements in the heap
    for(int i = 0; i < k; ++i){
        q.push(arr[i]);
    }

    // push each element and maintain the size
    for(int i = k; i < n; ++i){
        q.push(arr[i]);
        q.pop();
    }

    while(q.empty() == false){
        cout << q.top() << " ";
        q.pop();
    }
}


int main() {
    int arr[10];
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    printBestK(arr, n, 3);
}
