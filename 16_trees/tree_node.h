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