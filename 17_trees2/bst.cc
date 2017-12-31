// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include "tree_node.h"
#include <queue>
using namespace std;

TreeNode* insertInBST(TreeNode* root, int x){
    if (root == NULL){
        TreeNode* tmp = new TreeNode(x);
        return tmp;
    }

    if (x < root->data){
        root->left = insertInBST(root->left , x);
        return root;
    } else{
        root->right = insertInBST(root->right, x);
        return root;
    }
}

TreeNode* createBST(){
    TreeNode* root = NULL;
    int x;
    cin >> x;

    while(true){
        if (x == -1) break;
        root = insertInBST(root, x);
        cin >> x;
    }
    return root;
}

void printLevelOrder(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    TreeNode* MARKER = NULL;
    q.push(root);
    q.push(MARKER);

    while (q.empty() == false) {
        TreeNode* cur = q.front();
        q.pop();

        if (cur == MARKER) {
            // marker encountered
            // level is complete
            // cout << "0" << " ";
            cout << endl;
            if (q.empty() == false) q.push(MARKER);
            continue;
        }

        cout << cur-> data << " ";
        if (cur->left)  q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}


int main(){
    TreeNode* root = createBST();
    printLevelOrder(root);
    
}