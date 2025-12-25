/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    Node* pre;
    Node* suc;
  public:
    Solution() {
        pre = NULL;
        suc = NULL;
    }
    
    void solve(Node* root, int key) {
        if(root == NULL) return;
        
        if(root -> data > key) {
            suc = root;
            solve(root -> left, key);
        }
        else if(root -> data < key) {
            pre = root;
            solve(root -> right, key);
        }
        else {
            solve(root -> left, key);
            solve(root -> right, key);
        }
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        solve(root, key);
        return {pre, suc};
    }
};