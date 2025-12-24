#include <iostream>
using namespace std;
// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



class Solution {
public:
    // Function to change the values of the nodes
    // based on the sum of its children's values.
    void changeTree(TreeNode* root) {
        if(root == NULL) return;
        
        int child = 0;
        
        if(root -> left) {
            child += root->left->val;
        }
        if(root -> right) {
            child += root->right->val;
        }
        
        if(root->val >= child) {
            if(root -> left) {
                root->left->val = root->val;
            }
            else if(root -> right) {
                root->right->val = root->val;
            }
        }
        
        changeTree(root -> left);
        changeTree(root -> right);
        
        int total = 0;
        
        if(root -> left) {
            total += root->left->val;
        }
        if(root -> right) {
            total += root->right->val;
        }
        
        if(root -> left or root -> right) {
            root -> val = total;
        }
    }
};


// Function to print the inorder
// traversal of the tree
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(7);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(30);
    // root->left->right->left = new TreeNode(7);
    // root->left->right->right = new TreeNode(4);

    Solution sol;

    // Print the inorder traversal
    // of tree before modification
    cout << "Binary Tree before modification: ";
    inorderTraversal(root);
    cout << endl;

    // Call the changeTree function
    // to modify the binary tree
    sol.changeTree(root);

    // Print the inorder traversal
    // after modification
    cout << "Binary Tree after Children Sum Property: " ;
    inorderTraversal(root);
    cout << endl;

    return 0;
}
                