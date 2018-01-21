// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printSet(int a[], int ans[], int be, int n, int k, int sze){
    if (sze == 0){
        for(int i = 0; i < k; ++i){
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }

    if (be >= n) return;    // invalid range

    for(int i = be; i <= n - sze;  ++i){
        ans[k] = a[i];
        printSet(a, ans, i + 1, n, k + 1, sze - 1);
    }

}

int main(){
    int     arr[] = {1, 2, 3, 4};
    int n = 4;
    int ans[4];
    printSet(arr, ans, 0, 4, 0, 3);
}   