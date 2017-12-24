// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

// create Array
int * createArr(int n){
    int * ptr = new int[n];
    return ptr;
}

// Init array
void initialiseArr(int arr[], int n){
    for(int i = 0; i < n; ++i){
        arr[i] = 0;
    }
}

// update arr
void updateArr(int *arr, int n, int val){
    for (int i = 0; i < n; ++i)
    {
        arr[i] = val;
    }
}

// print arr
void displayArr(int arr[], int n){
    for (int i = 0; i < n; ++i)
    {
        cout << *(arr + i) << " " ;
    }
}

int main(){
    int n;
    cin >> n;

    int * arr = createArr(n);
    initialiseArr(arr, n);

    updateArr(arr, n, 5);

    displayArr(arr, n);

    delete [] arr;

}