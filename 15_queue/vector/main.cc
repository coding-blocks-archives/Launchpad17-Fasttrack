// main.cc
#include <iostream> // standard wala
#include "vector.h" // apna wala
using namespace std;

int main(){
    Vector v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    // v[i] ==> v.at(i)
    for(int i = 0; i < v.sizeFunc(); ++i){
        cout << v.at(i) << endl;
    }
}


