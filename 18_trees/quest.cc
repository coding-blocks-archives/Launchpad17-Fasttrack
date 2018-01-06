// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

void rootToLeaf(TreeNode* root, vector<TreeNode*>& v){

    if (!root){
        return;
    }

    if (!root->left && !root->right){
        //leaf node
        v.push_back(root);
         for(int i = 0; i < v.size(); ++i){
            cout << v[i]->data << " ";
        }
        v.pop_back();
        cout << endl;
    }

    v.push_back(root);  // address...ptr
    rootToLeaf(root->left, v);
    rootToLeaf(root->right, v);
    v.pop_back();
}

void rootToLeaf(TreeNode* root){
    // wrapper function
    vector<TreeNode*> v;
    rootToLeaf(root, v);
}


void rightView(){}
int childOrParent(){}
void deleteFromBST(){}
bool isBST(){}
TreeNode* convertIntoBST(){}

//=============================================

int main(){
    TreeNode* root = levelOrderInput();
    rootToLeaf(root);
}
