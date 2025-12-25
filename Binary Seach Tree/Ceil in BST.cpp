class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ans = -1;
        
        while(root) {
            if(root -> data < x) {
                root = root -> right;
            }
            else if(root -> data > x) {
                ans = root -> data;
                root = root -> left;
            }
            else {
                ans = root -> data;
                break;
            }
        }
        
        return ans;
    }
};
