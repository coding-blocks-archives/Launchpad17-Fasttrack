// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

void rootToLeaf(TreeNode* root, vector<TreeNode*>& v) {

    if (!root) {
        return;
    }

    if (!root->left && !root->right) {
        //leaf node
        v.push_back(root);
        for (int i = 0; i < v.size(); ++i) {
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

void rootToLeaf(TreeNode* root) {
    // wrapper function
    vector<TreeNode*> v;
    rootToLeaf(root, v);
}

void rightView(TreeNode* root, int curLevel, int& levelPrintedSoFar) {
    if (root == NULL) {
        return;
    }

    if (curLevel == levelPrintedSoFar + 1) {
        cout << root->data << " ";
        ++levelPrintedSoFar;
    }
    rightView(root->right, curLevel + 1, levelPrintedSoFar);
    rightView(root->left, curLevel + 1, levelPrintedSoFar);
}


bool isBST(TreeNode* root, int minVal, int maxVal) {
    if (root == NULL) return true;

    return (
               (root->data >= minVal && root->data <= maxVal) &&
               isBST(root->left, minVal, root->data) &&
               isBST(root->right, root->data, maxVal)
           );
}

void deleteFromBST() {}

pair<TreeNode*, TreeNode*> convertIntoLL(TreeNode* root) {

    if (root == NULL) {
        pair<TreeNode*, TreeNode*> p(NULL, NULL);
        return p;
    }

    pair<TreeNode*, TreeNode*> leftAns = convertIntoLL(root->left);
    pair<TreeNode*, TreeNode*> rightAns = convertIntoLL(root->right);

    pair<TreeNode*, TreeNode*> ans(NULL, NULL);

    if (leftAns.first) {
        ans.first = leftAns.first;      //ans.head = left.head
        root->left = leftAns.second;    // ans.left = leftAns.tail
        leftAns.second->right = root;
    } else {
        ans.first = root;
        root->left = NULL;
    }

    if (rightAns.first){
        root->right = rightAns.first;
        ans.second = rightAns.second;   //ans.tail = right.tail 
        rightAns.first->left = root;
    } else{
        ans.second = root;  
        root->right = NULL; // redundant
    }
    return ans;
}

void printList(TreeNode* head){
    TreeNode* cur = head;
    while(cur){
        if (cur->left) cout << "(" << cur->left->data << ")";
        cout << cur->data;
        if (cur->right) cout << "(" << cur->right->data << ")";
        cout << "--->";
        cur = cur->right;
    }
}


//=============================================

int main() {
    // TreeNode* root = levelOrderInput();
    // rootToLeaf(root);

    // TreeNode* root = levelOrderInput();
    // int levelPrinted = 0;
    // rightView(root, 1, levelPrinted);

    // const int inf = (int)1e6;
    // bool ans = isBST(root, -inf, inf);
    // cout << ans;

    TreeNode* root = createBST();
    pair<TreeNode*, TreeNode*> ans = convertIntoLL(root);
    printList(ans.first);

}

