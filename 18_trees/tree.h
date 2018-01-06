#include <iostream>
#include <queue>
using namespace std;

#ifndef TREE_NODE_H
#define TREE_NODE_H
class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d){
        data = d;
        left = 0;
        right = 0;
    }
};
#endif

#ifndef TREE_H
#define TREE_H
TreeNode* levelOrderInput() {
    int x;
    cin >> x;
    if (x == -1) return NULL;

    TreeNode* root = new TreeNode(x);

    queue<TreeNode*> q;     // GET
    q.push(root);           // SET

    while (q.empty() == false) {
        TreeNode* cur = q.front();
        q.pop();

        // cout << "left child of " << cur->data << " ";
        cin >> x;
        if (x != -1) {
            cur->left = new TreeNode(x);
            q.push(cur->left);
        }

        // cout << "right child of " << cur->data << " ";
        cin >> x;
        if (x != -1) {
            cur->right = new TreeNode(x);
            q.push(cur->right);
        }
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
#endif