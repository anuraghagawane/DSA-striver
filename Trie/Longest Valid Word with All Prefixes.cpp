struct Node {
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void increaseEnd() {
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void deleteEnd() {
        cntEndWith--;
    }

    void reducePrefix() {
        cntPrefix--;
    }
};

/* Define a class for the
trie data structure */
class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    /* Function to insert
    a word into the trie */
    void insert(string word) {
        Node* node = root;

        for(int i = 0; i < word.size(); i++) {
            if(!node -> containsKey(word[i])) {
                node->put(word[i], new Node());
            }

            node = node -> get(word[i]);

            node -> increasePrefix();
        }

        node -> increaseEnd();
    }

    /* Function to count the number
    of words equal to a given word */
    int countWordsEqualTo(string word) {
        Node* node = root;

        for(int i = 0; i < word.size(); i++) {
            if(node -> containsKey(word[i])) {
                node = node -> get(word[i]);
            } else {
                return 0;
            }
        }

        return node -> cntEndWith;
    }

    /* Function to count the number of
    words starting with a given prefix */
    int countWordsStartingWith(string word) {
        Node* node = root;

        for(int i = 0; i < word.size(); i++) {
            if(node -> containsKey(word[i])) {
                node = node -> get(word[i]);
            } else {
                return 0;
            }
        }

        return node -> cntPrefix;
    }

    /* Function to erase a
    word from the trie */
    void erase(string word) {
        Node* node = root;

        for(int i = 0; i < word.size(); i++) {
            if(node -> containsKey(word[i])) {
                node-> reducePrefix();
                node = node -> get(word[i]);
            } else {
                return;
            }
        }

        node -> deleteEnd();
    }
    
    bool isWordPrefix(string word) {
        Node* node = root;
        
        for(auto ch: word) {
            node = node -> get(ch);
            if(node -> cntEndWith == 0) {
                return false;
            } 
        }
        
        
        return true;
    }
};

class Solution {
public:
    string longestValidWord(vector<string>& words) {
        // code here
        Trie trie;
        
        for(auto word: words) {
            trie.insert(word);
        }
        
        string ans = "";
        for(auto word: words) {
            if(trie.isWordPrefix(word)) {
                if(word.length() == ans.length()) ans = min(word, ans);
                else if(word.length() > ans.length()) ans = word;
            }
        }
        return ans;
    }
};