struct Node {
    Node* links[2];

    bool containsKey(int bit) {
        return links[bit] != NULL;
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit) {
        links[bit] = new Node();
    }
};

class Trie {
    Node* root = new Node();
public:
    void insert(int num) {
        Node* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                node -> put(bit);
            }
            node = node -> get(bit);
        }
    }

    int getMaxXor(int num) {
        Node* node = root;
        int maxXor = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(node->containsKey(1-bit)) {
                maxXor |= (1 << i);
                node = node -> get(1 - bit);
            }
            else {
                node = node -> get(bit);
            }
        }

        return maxXor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;

        for(auto num: nums) trie.insert(num);

        int maxXor = 0;

        for(auto num: nums) maxXor = max(maxXor, trie.getMaxXor(num));

        return maxXor;
    }
};