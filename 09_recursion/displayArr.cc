// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) cin >> arr[i];
}

void printArr(int arr[], int n) {
    // printArr prints the n elements, I repeat n elements
    // from [0, n-1]

    // 10 20 30 40 50
    // array is empty...we cant do anything
    if (n == 0) return ;


    // 10 20 30 40
    printArr(arr, n - 1);
    // 50
    cout << " " << arr[n - 1]; // indices!!
}

// [2, 4]
// 30 40 50

void printArr(int arr[], int be, int en) {
    if (be > en) return;

    cout << arr[be] << " ";
    printArr(arr, be + 1, en);
}

void printRev(int arr[], int n) {
    if (n == 0) return;

    cout << arr[n - 1] << " ";
    printRev(arr, n - 1);
}

int max(int x, int y) {
    return (x > y) ? x : y;
}

int largest(int arr[], int be, int en) {
    if (be > en) {      // emptiness
        const int inf = 10000000;
        return -inf;
    }

    // recursive
    int largestInRem = largest(arr, be + 1, en);
    int ans = max(largestInRem, arr[be]);
    return ans;
}


int findElement(int arr[], int be, int en, int elementToSearch) {
    if (be > en) {
        // empty arr
        return -1;
    }

    if (arr[be] == elementToSearch) return be;

    // int ansFromRem = findElement(arr, be + 1, en, elementToSearch);
    // return ansFromRem;

    return findElement(arr, be + 1, en, elementToSearch);
}


void bubbleSort(int arr[], int be, int en) {
    // HW : think from the end
    if (be >= en) return;

    bubbleSort(arr, be + 1, en);
    if (arr[be] > arr[be + 1]) {

        int temp = arr[be];
        arr[be] = arr[be + 1];
        arr[be + 1] = temp;

        bubbleSort(arr, be + 1, en);
    }
}

bool isSorted(int arr[], int be, int en) {
    if (be >= en) {
        // empty
        return true;
    }

    bool cur2Elements = (arr[be] > arr[be + 1]) ? false : true;
    if (cur2Elements == true){
        return isSorted(arr, be + 1, en);
    } else {
        return false;
    }
}

/*bool isSorted(int arr[], int be, int en){
    if (be >= en) return true;

    return arr[be] < arr[be + 1] && isSorted(arr, be + 1, en);
}*/


int sumArr(int arr[], int n){
    // sum of n of elements
    if (n <= 0) return 0;

    int remSum = sumArr(arr, n - 1);
    int totalSum = arr[n - 1] + remSum;
    return totalSum;
}

int largestPos(int arr[], int n){
    if (n <= 0) return -1;

    int largestPosInRemArr = largestPos(arr, n - 1);
    int reqPos = n - 1;

    if (largestPosInRemArr != -1){
        reqPos = arr[largestPosInRemArr] > arr[n - 1] ? largestPosInRemArr : n - 1;
    }   
    return reqPos;
}
    


void selectionSort(int arr[], int n){
    // empty...base case
    if (n <= 0) return;

    // swap largest with end
    int largestPosInRemArr = largestPos(arr, n);
    swap(arr[largestPosInRemArr], arr[n - 1]);

    // selection sort
    selectionSort(arr, n - 1);
}


void printDigit(int digit){
    switch(digit){
        case 0: 
            cout << "zero ";
            break;
        case 1 : 
            cout << "one ";
            break;
        case 2 : 
            cout << "two ";
            break;
        case 3 : 
            cout << "three ";
            break;
        case 4 : 
            cout << "four ";
            break;
        case 5 : 
            cout << "five ";
            break;
        case 6 : 
            cout << "six ";
            break;
        default: 
            cout << "doItYourSelf";
    }
}

void printNumber(int num){
    if (num <= 0) return;

    int remNum = num / 10;
    printNumber(remNum);

    printDigit(num % 10);
}


int main() {
    int n;
    int arr[100];
    cin >> n;
    // inputArr(arr, n);

    // printArr(arr, n);

    // int be, en;
    // cin >> be >> en;
    // printArr(arr, be, en);

    // printRev(arr, n);

    // int ans = largest(arr, 0, n - 1);
    // cout << ans;

    // int x;
    // cin >> x;
    // cout << findElement(arr, 0, n - 1, x);

    // bubbleSort(arr, 0 , n - 1);
    // printArr(arr, n);

    // bool ans = isSorted(arr, 0, n - 1);
    // cout << ans;

    // cout << sumArr(arr, n);

    // selectionSort(arr, n);
    // printArr(arr, n);

    printNumber(n);
}