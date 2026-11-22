#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int countNode(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + countNode(root->left) + countNode(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    int count = countNode(root);
    std::cout << count;
    return 0;
}

