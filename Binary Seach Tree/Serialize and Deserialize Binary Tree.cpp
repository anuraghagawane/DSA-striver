/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                auto front = q.front();
                q.pop();
                if(front == NULL) {
                    serialized += "N,";
                    continue;
                };
                if(front -> left) {
                    q.push(front -> left);
                }
                else {
                    q.push(NULL);
                }

                if(front -> right) {
                    q.push(front -> right);
                }
                else {
                    q.push(NULL);
                }

                serialized += to_string(front->val) + ",";
            }
        }
        if(!serialized.empty()) serialized.pop_back(); 
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return NULL;
        vector<TreeNode*> TreeNodes = splitDataIntoTreeNodes(data);
        int i = 0;
        int j = 0;
        TreeNode* root = TreeNodes[0];
        TreeNode* curr = root;
        j++;
        while(j < TreeNodes.size()) {
            if(curr == NULL && i < j) {
                i++;
                curr = TreeNodes[i];
                continue;
            }
            curr -> left = TreeNodes[j];
            j++;
            curr -> right = TreeNodes[j];
            j++;
            i++;
            curr = TreeNodes[i];
        }
        return root;
    }

private:
    vector<TreeNode*> splitDataIntoTreeNodes(string data) {
        vector<string> stringNodes = splitDataIntoStringArray(data);
        vector<TreeNode*> TreeNodes;

        for(auto s: stringNodes) {
            if(s == "N") {
                TreeNodes.push_back(NULL);
            }
            else {
                TreeNodes.push_back(new TreeNode(stoi(s)));
            }
        }

        return TreeNodes;
    }
    vector<string> splitDataIntoStringArray(string data) {
        if(data.length() == 0) return {};
        vector<string> ans;
        int i = 0;
        int j = 0;

        string temp = "";
        while(j < data.length()){
            if(data[j] == ',') {
                ans.push_back(data.substr(i, j - i));
                j++;
                i = j;
            }
            else {
                j++;
            }
        }
        ans.push_back(data.substr(i, j - i));
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));