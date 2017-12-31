// deepak@codingblocks.com
#include <iostream>
#include "tree_node.h"
#include <queue>
using namespace std;

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

int height(TreeNode* root) {
    if (root == NULL) return 0;

    int leftHt = height(root->left);
    int rightHt = height(root->right);
    int curHt = max(leftHt, rightHt) + 1;
    return curHt;
}

void printNode(TreeNode* x) {
    cout << x << " ";
    if (x) cout << x->data;
    cout << endl;
}

int cntNodes(TreeNode* root) {
    if (!root) return 0;

    return cntNodes(root->left) + 1 + cntNodes(root->right);
}

int nodesGreater(TreeNode* root, int x) {
    if (root == NULL) {
        return 0;
    }

    int leftCnt = nodesGreater(root->left, x);
    int rightCnt = nodesGreater(root->right, x);

    return leftCnt + rightCnt + (root->data > x);
}


TreeNode* mirror(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    TreeNode* leftMirror = mirror(root->left);
    TreeNode* rightMirror = mirror(root->right);
    root->right = leftMirror;
    root->left = rightMirror;
    return root;
}


int abs(int x) {
    return x < 0 ? -x : x;
}

bool isHeightBalanced(TreeNode* root) {
    if (!root) {
        return true;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    if (abs(leftHt - rightHt) > 1) return false;

    return isHeightBalanced(root->left) && isHeightBalanced(root->right);
}

struct Pair {   // by default, public
    int height;
    bool bal;
};

Pair isHeightBalanced_Optimised(TreeNode* root) {
    if (root == NULL) {
        Pair tmp;
        tmp.height = 0;
        tmp.bal = true;
        return tmp;
    }

    Pair lftAns = isHeightBalanced_Optimised(root->left);
    Pair rghtAns = isHeightBalanced_Optimised(root->right);

    Pair ans;
    ans.height = max(lftAns.height, rghtAns.height) + 1;
    ans.bal = lftAns.bal && rghtAns.bal &&
              (abs(lftAns.height - rghtAns.height) <= 1);
    return ans;

}

int max(int a, int b, int c) {  // function overloading
    return max(max(a, b), c);
}

int diameter(TreeNode* root) {
    if (root == NULL ) return 0;

    int leftHt = height(root->left);
    int rightHt = height(root->right);
    int curDia = leftHt + rightHt + 1;

    int leftDia = diameter(root->left);
    int rightDia = diameter(root->right);
    return max(curDia, leftDia, rightDia);
}

// Optimised Diameter HW

int getIdx(int arr[], int be, int en, int x){
    while(be <= en){
        if (arr[be] == x) return be;
        ++be;
    }
    return -1;
}

TreeNode* treeFromArr(int in[], int si, int ei, 
                      int pre[], int& bj, int ej){

    if (si > ei){
        return NULL;
    }

    TreeNode* root = new TreeNode(pre[bj]);
    
    int idxOfroot = getIdx(in, si, ei, root->data);

    bj = bj + 1;
    root->left = treeFromArr(in, si, idxOfroot - 1,
                             pre, bj, ej);

    root->right = treeFromArr(in, idxOfroot + 1, ei, 
                              pre, bj, ej);
    return root;
}


int main() {
    // TreeNode* root = levelOrderInput();

    // int cnt = cntNodes(root);
    // cout << cnt << endl;

    // int x; cin >> x;
    // int cnt = nodesGreater(root, x);
    // cout << cnt;

    // root = mirror(root);
    // printLevelOrder(root);

    // Pair ans = isHeightBalanced_Optimised(root);
    // cout << ans.bal << endl;

    // int dia = diameter(root);
    // cout << dia << endl;

    int pre[] = {1, 2, 4, 3, 5};
    int in[] = {2, 4, 1, 5, 3};
    int bj = 0;
    TreeNode* ans = treeFromArr(in, 0, 4, pre, bj, 4);
    printLevelOrder(ans);

    // int levelPrintedSoFar = 0;
    // printRightView(root, 0, levelPrintedSoFar);

    // bool ans = equalBreak(root, cnt);
    // cout << ans;

}
