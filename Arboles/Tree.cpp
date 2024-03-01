#include "Tree.h"

struct TreeNode* createNode(int value) {
    return new TreeNode(value);
}

struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root;
}

void inOrderTraversal(struct TreeNode* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        std::cout << root->value << " ";
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct TreeNode* root) {
    if (root != nullptr) {
        std::cout << root->value << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct TreeNode* root) {
    if (root != nullptr) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::cout << root->value << " ";
    }
}

void printLevelOrder(struct TreeNode* root) {
    if (root == nullptr)
        return;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int nodeCount = q.size();
        while (nodeCount > 0) {
            TreeNode* node = q.front();
            std::cout << node->value << " ";
            q.pop();
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
            nodeCount--;
        }
        std::cout << std::endl;
    }
}

TreeNode* leftRotate(TreeNode* node) {
    TreeNode* x = node->right;
    node->right = x->left;
    x->left = node;
    x->color = node->color;
    node->color = 1;
    return x;
}

TreeNode* rightRotate(TreeNode* x) {
    TreeNode* node = x->left;
    x->left = node->right;
    node->right = x;
    node->color = x->color;
    x->color = 1;
    return node;
}