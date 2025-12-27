/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> mp;
    unordered_set<int> vis;
public:
    Node* createOrReturnExistingNode(int val) {
        if(mp.find(val) != mp.end()) return mp[val];
        Node* newNode = new Node(val);
        mp[val] = newNode;
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        queue<Node*> q;

        q.push(node);

        Node* newHead = q.front();
        Node* currNode = createOrReturnExistingNode(newHead->val);

        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            if(vis.find(front->val) != vis.end()) {
                continue;
            }
            vis.insert(front->val);

            Node* currNode = createOrReturnExistingNode(front->val);

            for(auto node : front->neighbors) {
                Node* neighbors = createOrReturnExistingNode(node -> val);
                currNode->neighbors.push_back(neighbors);
                if(vis.find(node->val) == vis.end()) {
                    q.push(node);
                }
            }

        }

        return currNode;
    }
};