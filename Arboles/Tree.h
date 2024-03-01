#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
    bool color; // 1 for RED, 0 for BLACK

    TreeNode(int val) : value(val), left(nullptr), right(nullptr), color(1) {}
};

struct TreeNode* createNode(int value);
struct TreeNode* insert(struct TreeNode* root, int value);
void inOrderTraversal(struct TreeNode* root);
void preOrderTraversal(struct TreeNode* root);
void postOrderTraversal(struct TreeNode* root);
void printLevelOrder(struct TreeNode* root);
TreeNode* leftRotate(TreeNode* node);
TreeNode* rightRotate(TreeNode* x);

#endif // TREE_H