/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void left(Node* root, vector<int>& leftVec) {
        if(root == NULL || (root -> left == NULL && root -> right == NULL)) {
            return;
        }
        
        leftVec.push_back(root->data);
        
        if(root -> left != NULL)
            left(root -> left, leftVec);
        else if(root -> right != NULL) 
            left(root -> right, leftVec);
    }
    
    void right(Node* root, vector<int>& rightVec) {
        if(root == NULL || (root -> left == NULL && root -> right == NULL)) {
            return;
        }
        
        if(root -> right != NULL) right(root -> right, rightVec);
        else if(root -> left != NULL) right(root -> left, rightVec);
        
        rightVec.push_back(root->data);
    }
    
    void bound(Node* root, vector<int>& boundVec) {
        if(root == NULL) {
            return;
        }
        
        if(root -> left == NULL && root -> right == NULL)
            boundVec.push_back(root->data);
        
        bound(root -> left, boundVec);
        bound(root -> right, boundVec);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        
        ans.push_back(root->data);
        left(root->left, ans);
        bound(root->left, ans);
        bound(root->right, ans);
        right(root->right, ans);
        
        return ans;
    }
};