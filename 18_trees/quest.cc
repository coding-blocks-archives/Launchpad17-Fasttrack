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

    if (rightAns.first) {
        root->right = rightAns.first;
        ans.second = rightAns.second;   //ans.tail = right.tail
        rightAns.first->left = root;
    } else {
        ans.second = root;
        root->right = NULL; // redundant
    }
    return ans;
}

TreeNode* successor(TreeNode* root) {
    if (root == NULL) return NULL;

    TreeNode* parent = root;
    TreeNode* cur = root->right;

    while (cur && cur->left) {
        parent = cur;
        cur = cur->left;
    }

    if (cur) parent->left = cur->right;
    return cur;
}

TreeNode* deleteFromBST(TreeNode* root, int x) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == x) {
        // if root is a leaf
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }

        // if root has one child
        if (!root->left) {
            TreeNode* tmp = root->right;
            delete root;
            return tmp;
        }

        if (!root->right) {
            TreeNode* tmp = root->left;
            delete root;
            return tmp;
        }

        // if root has 2 children
        TreeNode* inOrderSuccessor = successor(root);

        inOrderSuccessor->left = root->left;
        inOrderSuccessor->right = root->right;

        delete root;
        return inOrderSuccessor;
    }

    if (root->data > x) {
        root->left = deleteFromBST(root->left, x);
        return root;
    } else {
        root->right = deleteFromBST(root->right, x);
        return root;
    }
}

void printList(TreeNode* head) {
    TreeNode* cur = head;
    while (cur) {
        if (cur->left) cout << "(" << cur->left->data << ")";
        cout << cur->data;
        if (cur->right) cout << "(" << cur->right->data << ")";
        cout << "--->";
        cur = cur->right;
    }
}

int bestSumExcludingChildren(TreeNode* root, bool isIncluded) {
    if (root == NULL) {
        return 0;
    }

    int ans[5] = {};

    // root exc, left inc
    if (!isIncluded) {
        int leftAns1 = bestSumExcludingChildren(root->left, true);
        int rightAns1 = bestSumExcludingChildren(root->right, true);
        int ans[0] = max(leftAns1, 0) + max(rightAns1, 0);


        // root exc, left exc
        int leftAns2 = bestSumExcludingChildren(root->left, false);
        int rightAns2 = bestSumExcludingChildren(root->right, false);
        int ans[1] = max(leftAns, 0) + max(rightAns, 0);

        int ans[2] = max(leftAns1, 0) + max(rightAns2, 0);
        int ans[3] = max(rightAns1, 0) + max(leftAns1, 0);
    }
    
    // root inc
    int ans[4] = max(leftAns2, 0) + max(rightAns2, 0) + max(root->data, 0);

    int* ansFinal = max_element(ans, ans + 4);
    return *ansFinal;
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

    // TreeNode* root = createBST();
    // pair<TreeNode*, TreeNode*> ans = convertIntoLL(root);
    // printList(ans.first);

    // TreeNode* root = createBST();
    // int x; cin >> x;
    // root = deleteFromBST(root, x);
    // printLevelOrder(root);

    int ans = bestSumExcludingChildren(root);


}

