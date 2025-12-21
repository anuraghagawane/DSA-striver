/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    void traverse(Node* root, int horDis, int level,  map<int, pair<int, int>>& mp) {
        if(root == NULL) return;
        
        if(mp.find(horDis) != mp.end()) {
            auto [prevLevel, prevVal] = mp[horDis];
            if(prevLevel <= level) {
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
    vector<int> bottomView(Node *root) {
        // code here
        // horizontal distance, {level, NodeVal}
        map<int, pair<int, int>> mp;
        
        traverse(root, 0, 0, mp);
        
        vector<int> ans;
        for(auto m: mp){
            ans.push_back(m.second.second);
        }
        
        return ans;
    }
};