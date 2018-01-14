// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include "tree.h"
#include <map>
#include <vector>
using namespace std;

map<int, vector<int> > m;

void printVertical(TreeNode* root, int curDist){
    if (root == NULL){
        return;
    }

    m[curDist].push_back(root->data);
    printVertical(root->left, curDist - 1);
    printVertical(root->right, curDist + 1);
}

// wrapper function
void printVertical(TreeNode* root){
    printVertical(root, 0);

    map<int, vector<int> >::iterator itBegin = m.begin();
    map<int, vector<int> >::iterator itEnd   = m.end();

    typedef map<int, vector<int> >::iterator mit;

    for(mit it = itBegin; it != itEnd; ++it){
        int dist = it->first;           // gives me the key
        const vector<int>& v = it->second;     // gives me the value

        cout << dist << "\t: ";
        for(int i = 0; i < v.size(); ++i){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}


int main(){
    TreeNode* root = levelOrderInput();
    printVertical(root);
    
}