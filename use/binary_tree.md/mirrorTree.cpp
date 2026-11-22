#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void mirrorTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    mirrorTree(root);
    // Теперь: root->right = 2, root->left = 3, root->right->right = 4
    
    return 0;
}
