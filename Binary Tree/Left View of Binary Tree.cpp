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
    void traverse(Node* root, int currHeight, vector<int>& view) {
        if(root == NULL) {
            return;
        }
        
        if(view.size() == currHeight) {
            view.push_back(root->data);
        }
        
        traverse(root->left, currHeight+1, view);
        traverse(root->right, currHeight+1, view);
    }
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> view;
        traverse(root, 0, view);
        
        return view;
    }
};