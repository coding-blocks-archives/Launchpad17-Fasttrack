// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <algorithm>
using namespace std;

int parent(int i) { return (i - 1) / 2;}
int left(int i) { return 2 * (i) + 1; }
int right(int i) { return 2 * (i) + 2; }

void heapify(int arr[], int be, int en, int i) {
    int pos = i;
    if (left(i) <= en && arr[pos] < arr[left(i)]) {
        pos = left(i);
    }
    if (right(i) <= en && arr[pos] < arr[right(i)]) {
        pos = right(i);
    }
    if (i != pos) {
        swap(arr[i], arr[pos]);
        i = pos;
        heapify(arr, be, en, i);
    }
}

void build_heap(int arr[], int be, int en) {
    int i = parent(en);
    while(i >= 0){
        heapify(arr, be, en, i);
        i--;
    }
}



void heapsort(int arr[], int be, int en) {
    build_heap(arr, be, en);


    for (int i = en; i >= be;) {
        swap(arr[i], arr[be]);
        --i;
        heapify(arr, be, i, 0);
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    // make_heap(arr + 0, arr + 5, greater<int>);
    heapsort(arr, 0, 4);
    // cout << arr[0];
    for (int i = 0; i < 5; ++i)
    {
        cout << arr[i];
    }

//     for (int i = 0; i < 5; ++i) {
//         swap(i, 5);
//         heapify(i);
//     }
}