#include<bits/stdc++.h>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Solution class containing the traversal function
class Solution {
public:
    // Function to get the Preorder,
    // Inorder and Postorder traversal
    // Of Binary Tree in One traversal
    vector<vector<int>> preInPostTraversal(Node* root) {
        // Vectors to store traversals
        vector<vector<int>> ans(3);

        // Node, current traversal=> 0: pre, 1: in, 2: post
        stack<pair<Node*, int>> st;

        st.push({root, 0});

        while(!st.empty()) {
            auto [node, trav] = st.top();
            st.pop();
            if(trav == 0) {
                ans[0].push_back(node->data);
                st.push({node, 1});
                if(node->left != NULL) st.push({node->left, 0});
            }
            else if(trav == 1) {
                ans[1].push_back(node->data);
                st.push({node, 2});
                if(node->right != NULL) st.push({node->right, 0});
            }
            else {
                ans[2].push_back(node->data);
            }
        }

        return ans;
    }
};
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Create object of Solution class
    Solution sol;
    
    // Getting the pre-order, in-order,
    // and post-order traversals
    vector<int> pre, in, post;
    vector<vector<int>> traversals = sol.preInPostTraversal(root);

    // Extracting the traversals
    // from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    // Printing the traversals
    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}