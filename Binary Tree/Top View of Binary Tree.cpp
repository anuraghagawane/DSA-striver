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
    void traverse(Node* root, int horDis, int level,  map<int, pair<int, int>>& mp) {
        if(root == NULL) return;
        
        if(mp.find(horDis) != mp.end()) {
            auto [prevLevel, prevVal] = mp[horDis];
            if(prevLevel > level) {
                mp[horDis] = {level, root->data};
            }
        }
        else {
            mp[horDis] = {level, root->data};
        }
        
        traverse(root->left, horDis-1, level+1, mp);
        traverse(root->right, horDis+1, level+1, mp);
    }
  public:
    vector<int> topView(Node *root) {
        // code here
        
        // ****************
        // preorder traversal approach
        // ****************
        
        // // horizontal distance, {level, NodeVal}
        // map<int, pair<int, int>> mp;
        
        // traverse(root, 0, 0, mp);
        
        // vector<int> ans;
        // for(auto m: mp){
        //     ans.push_back(m.second.second);
        // }
        
        // return ans;
        
        
        // ****************
        // using level order traversal 
        // *****************
        
        // horizontal distance, val
        map<int,int> mp;
        
        // horizontal distance, Node
        queue<pair<int, Node*>> q;
        q.push({0, root});
        
        while(!q.empty()){
            auto [horDis, node] = q.front();
            q.pop();
            
            if(mp.find(horDis) == mp.end()) {
                mp[horDis] = node->data;
            }
            
            if(node->left != NULL) {
                q.push({horDis - 1, node->left});
            }
            
            if(node->right != NULL) {
                q.push({horDis + 1, node->right});
            }
        }
        
        vector<int> ans;
        for(auto m: mp){
            ans.push_back(m.second);
        }
        
        return ans;
    }
};