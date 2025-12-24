/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* solve(Node* root) {
        if(root == NULL) return root;

        auto L = root -> left, R = root ->  right, N = root -> next;

        if(L) {
            L -> next = R;
            if(N) R -> next = N -> left;
            connect(L);
            connect(R);
        }

        return root;
    }
    Node* connect(Node* root) {
        // recursive dfs
        // return solve(root);
        
        // bfs
        // if(root == NULL) return NULL;

        // queue<Node*> q;

        // q.push(root);

        // while(!q.empty()) {
        //     int size = q.size();

        //     for(int i = 0; i < size; i++) {
        //         Node* front = q.front();
        //         q.pop();

        //         if(i==size-1) {
        //             front -> next = NULL;
        //         }
        //         else {
        //             front -> next = q.front();
        //         }

        //         if(front->left) {
        //             q.push(front->left);
        //         }
        //         if(front->right) {
        //             q.push(front->right);
        //         }
        //     }
        // }

        // return root;


        //space optimized

        auto head = root;

        for(; root; root = root -> left) {
            for(auto curr = root; curr; curr = curr -> next) {
                if(curr -> left) {
                    curr -> left -> next = curr -> right;
                    if(curr -> next) {
                        curr -> right -> next = curr -> next -> left;
                    }
                }
            }
        }

        return head;
    }
};