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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        level = 1;
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp(size);
            bool isltr = (level % 2 != 0);
            for(int i = 0; i < size; i++) {
                TreeNode* currNode = q.front();
                q.pop();

                if(isltr) {
                    temp[i] = currNode->val;
                }
                else {
                    temp[size - i - 1] = currNode -> val;
                }

                if(currNode -> left != NULL) q.push(currNode -> left);
                if(currNode -> right != NULL) q.push(currNode -> right);
            }

            ans.push_back(temp);
            level++;
        }

        return ans;
    }
};