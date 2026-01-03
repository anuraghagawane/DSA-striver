struct Node {
    Node* links[26];
    bool isEnd = false;
    bool containsKey(char ch) {
        return !(links[ch - 'a'] == NULL);
    }
    
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    Node* put(char ch) {
        links[ch - 'a'] = new Node();
    }
    
    void setEnd() {
        isEnd = true;
    }
    
    bool isEndFn() {
        return isEnd;
    }
};

class Solution {
  public:
    int countSubs(string& s) {
        // code here
        int cnt = 0;
        int n = s.length();
        Node* root = new Node();
        for(int i = 0; i < n; i++) {
            Node* node = root;
            for(int j = i; j < n; j++) {
                if(!(node -> containsKey(s[j]))) {
                    node -> put(s[j]);
                    cnt++;
                }
                node = node -> get(s[j]);
            }
        }
        
        return cnt;
    }
};