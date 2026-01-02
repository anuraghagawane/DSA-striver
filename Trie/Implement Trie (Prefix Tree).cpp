struct Node {
    bool isWord;
    Node* next[26];
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        auto head = root;
        for(auto ch: word) {
            auto nextNode = getNext(head, ch);
            head = nextNode;
        }
        head -> isWord = true;
    }
    
    bool search(string word) {
        auto head = root;
        for(auto ch: word) {
            auto nextNode = isNextPresent(head, ch);
            if(nextNode == NULL) return false;
            head = nextNode;
        }
        return head -> isWord;
    }
    
    bool startsWith(string prefix) {
        auto head = root;
        for(auto ch: prefix) {
            auto nextNode = isNextPresent(head, ch);
            if(nextNode == NULL) return false;
            head = nextNode;
        }

        return true;
    }

    ~Trie() {
        clear(root);  // Destructor calls cleanup
    }

    void clear(Node* node) {
        if (!node) return;
        
        // Recursively delete all children
        for (int i = 0; i < 26; i++) {
            clear(node->next[i]);
        }
        
        delete node;  // Actually free the memory
    }
private:
    Node* isNextPresent(Node* head, char ch) {
        return head -> next[ch - 'a'];
    }

    Node* getNext(Node* head, char ch) {
        if(head -> next[ch - 'a'] != NULL) return head -> next[ch - 'a'];
        Node* newNode = new Node();
        head -> next[ch - 'a'] = newNode;
        return head -> next[ch - 'a'];
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */