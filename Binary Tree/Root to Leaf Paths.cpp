/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    void traverse(Node* root, vector<int>& temp, vector<vector<int>>& ans) {
        if(root == NULL) return;
        temp.push_back(root->data);
        if(root->left == NULL && root -> right == NULL) {
            ans.push_back(temp);
        }
        traverse(root -> left, temp, ans);
        traverse(root -> right, temp, ans);
        temp.pop_back();
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        traverse(root, temp, ans);
        
        return ans;
        
    }
};