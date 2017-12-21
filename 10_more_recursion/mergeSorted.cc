// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void inputArr(int arr[], int n){
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

void outputArr(int arr[], int n){
    for(int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copyArr(int x[], int arr[], int be, int en){
    // HW: Manipulate indices
    // be = 3
    // en = 4

    while(be <= en){    // 3, 4
        x[be] = arr[be];    // x[3], x[4]; x[0], x[1]
        ++be;
    }
}


void mergeSorted(int arr[], int i, int ei, int j, int ej){
    // O(N)
    // until I have elements to compare, I will compare

    int x[100];
    int y[100];
    copyArr(x, arr, i, ei);
    copyArr(y, arr, j, ej);

    int k = i;  // and NOT zero
    while(i <= ei && j <= ej){
        if (x[i] < y[j]){
            arr[k] = x[i];
            ++i;
            ++k;
        } else {
            arr[k] = y[j];
            ++k;
            ++j;
        }
    }

    //If either array is exhausted, I ll copy the other one
    while(i <= ei){
        arr[k] = x[i];
        ++k;
        ++i; 
    }

    while(j <= ej){
        arr[k] = y[j];
        ++j;
        ++k;
    }
}

int binarySearch(int arr[], int be, int en, int elementToSearch){
    if (be > en){
        return - 1;
    }
    
    // recurrence
    int mid = (be + en) / 2;


    if (arr[mid] == elementToSearch){
        return mid;
    } else if (arr[mid] > elementToSearch){
        int ans = binarySearch(arr, be, mid - 1, elementToSearch);
        return ans;
    } else {
        return binarySearch(arr, mid + 1, en, elementToSearch);
    }

}


void mergeSort(int arr[], int be, int en){
    if (be >= en) return;

    int mid = (be + en) / 2;
    mergeSort(arr, be , mid);
    mergeSort(arr, mid + 1, en);
    mergeSorted(arr, be, mid, mid + 1, en);
}



int main(){
    int arr[100];
    int n;
    cin >> n;

    inputArr(arr, n);
    
    mergeSort(arr, 0, n - 1);

    // mergeSorted(arr, 0, 2, 3, 4); 
    outputArr(arr, n);   
}