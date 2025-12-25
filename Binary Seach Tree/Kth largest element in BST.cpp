/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
    int ans = -1;
  public:
    void solve(Node* root, int k, int& count) {
        if(root == NULL) return;
        if(ans != -1) return;
        solve(root -> right, k, count);
        count++;
        if(count == k) {
            ans = root -> data;
            return;
        }
        solve(root -> left, k, count);
    }
    int kthLargest(Node *root, int k) {
        // Your code here
        int count = 0;
        solve(root, k, count);
        
        return ans;
    }
};