// deepak@codingblocks.com
#include <iostream>
#include "tree_node.h"
#include <queue>
using namespace std;

TreeNode* createTree() {
// Takes input and converts it in a tree
    int x;
    cin >> x;

    if (x == -1) {
        return NULL;
    }

    TreeNode* root = new TreeNode(x);
    // cout << "Please enter the left subtree ";
    root->left = createTree();
    // cout << "Please enter the right subtree ";
    root->right = createTree();
    return root;
}

void printTree(TreeNode* root) {
    // prints the pre-order traversal(travelling/reading) of tree
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";  // My hat currently at root
    printTree(root->left);  // the left SUBTREE
    printTree(root->right); // the right SUBTREE
}

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

int height(TreeNode* root){
    if (root == NULL) return 0;

    int leftHt = height(root->left);
    int rightHt = height(root->right);
    int curHt = max(leftHt, rightHt) + 1;
    return curHt;
}

TreeNode* findNode(TreeNode* root, int x){
    if (root == NULL){
        return NULL;
    }

    if (x == root->data) return root;

    TreeNode* leftAns = findNode(root->left, x);
    if (leftAns != NULL) return leftAns;

    return findNode(root->right, x);
}

TreeNode* largestNode(TreeNode* root){
    if (root == NULL){
        return NULL;
    }

    TreeNode* ans = root;
    TreeNode* leftMax = largestNode(root->left);
    TreeNode* rightMax = largestNode(root->right);

    if (leftMax && leftMax->data > ans->data){
        ans = leftMax;
    }

    if (rightMax && rightMax->data > ans->data){
        ans = rightMax;
    }

    return ans;
}

void printNode(TreeNode* x){
    cout << x << " ";
    if (x) cout << x->data;
    cout << endl;
}

void printAtK(TreeNode* root, int k){
    if (!root) return; // if not root -- if root does not exists

    if (k == 1) {
        cout << root->data << " ";
        return;
    }

    printAtK(root->left, k -1);
    printAtK(root->right, k -1);

}

int main() {
    // TreeNode* root = createTree();
    // printTree(root);

    TreeNode* root = levelOrderInput();
    // printLevelOrder(root);

    // int ht = height(root);
    // cout << ht;

    // int x;
    // cin >> x;
    // TreeNode* ans = findNode(root, x);
    // cout << ans << " ";
    // if (ans) ans->data;

    // TreeNode* ans = largestNode(root);
    // printNode(ans);

    int k;
    cin >> k;
    printAtK(root, k);

}
