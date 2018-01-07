// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compareElements(const int& a, const int& b){
    return a > b;
}

class Elephant{
    int wt;
public:
    void setWt(int x){
        wt = x;
    }

    int getWt() const {
        return wt;
    }
};


bool compareElephants(const Elephant& A, const Elephant& B){
    return A.getWt() > B.getWt();
}

template <typename T>
void mySort(T* be, T* en, bool (*myComparator)(const T& a, const T& b)){
    while(be != en){
        //compare and swap
        T* tmp = be + 1;
        while(tmp != en){
            if (myComparator(*(tmp - 1), *tmp)){
                swap(*(tmp-1),*(tmp));
            }
                ++tmp;
        }
        --en;
    }
}



int main(){
    int arr[10] = {4, 30, -2,1};

    // sort(&arr[0], &arr[5]); // one element past the end element

    // sort (arr, arr + 10, compareElements);

    // for(int i = 0; i < 10; ++i) cout << arr[i] << " ";


    vector<Elephant> v(4);
    v[0].setWt(10);
    v[1].setWt(-10);
    v[2].setWt(30);
    v[3].setWt(40);


    mySort(arr, arr + 4, compareElements);
    for(int i = 0; i < 4; ++i){
        // cout << v[i].getWt() << " ";
        cout << arr[i] << " ";
    }
}