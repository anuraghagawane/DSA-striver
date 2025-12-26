/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;

public:
    BSTIterator(TreeNode* root, int isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();

        pushAll(reverse ? temp -> left : temp -> right);

        return temp -> val;
    }
private:
    void pushAll(TreeNode* root) {
        while(root) {
            st.push(root);
            root = reverse ? root -> right : root -> left;
        }
    }

};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while(i < j) {
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }

        return false;
    }
};