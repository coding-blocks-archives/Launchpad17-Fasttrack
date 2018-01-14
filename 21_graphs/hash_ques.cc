// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <map>      // unordered map --> O(1) else O(lg N)
#include <vector>
using namespace std;

vector<int> intersectionArray(int a1[], int a2[], int n1, int n2){
    map<int, int> map1;     // map for a1
    vector<int> v;

    // for every element in the array a1, push into map1
    for(int i = 0; i < n1; ++i){
        // map1.insert(a1[i], a1[i]);

        // pair<int, int> p(a1[i], a1[i]);
        // map1.insert(p);  // using insert function

        int key = a1[i];    
        map1[key] = a1[i];  // using assignment operator

    }

    // for every element in the array 2, search in map1
    for(int i = 0; i < n2; ++i){
        int cur = a2[i];

        // if key is found in the map1, push it into the vector
        if (map1.find(cur) != map1.end()){
            // exists
            v.push_back(cur);
        }
    }

    // return the vector
    return v;
}

void inputArr(int arr[], int n){
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
}

int main(){

    int a1[10], a2[10];
    int n1, n2;
    cin >> n1 >> n2;

    inputArr(a1, n1);
    inputArr(a2, n2);

    vector<int> ans = intersectionArray(a1, a2, n1, n2);

    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " ";
    }
    
}