/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool ans = true;
    int solve(Node* root) {
        if(root == NULL) return 0;
        
        if(!ans) return root->data;
        
        if(root -> left == NULL && root -> right == NULL) return root -> data;
        
        int left = solve(root -> left);
        int right = solve(root -> right);
        
        if(left + right != root -> data) {
            ans = false;
        }
        
        return root -> data;
    }
    
    bool isSumProperty(Node *root) {
        // code here
        solve(root);
        
        return ans;
    }
};