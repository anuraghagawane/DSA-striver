struct Node {
    int val;
    int key;
    Node* prev;
    Node* next;

    Node(int key, int val) {
        this->val = val;
        this->key = key;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
    unordered_map<int, Node*> mp;
    int cap;
    int size;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> next = head;
    }

    void addNode(Node* node) {
        Node* temp = head -> next;
        node -> prev = head;
        node -> next = temp;
        head -> next = node;
        temp -> prev = node;
    }

    void delNode(Node* node) {
        Node* prev = node -> prev;
        Node* next = node -> next;

        prev -> next = next;
        next -> prev = prev;

    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* curr = mp[key];
            mp.erase(key);
            delNode(curr);
            addNode(curr);
            mp[key] = head->next;

            return curr->val;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* curr = mp[key];
            mp.erase(key);
            delNode(curr);
        }

        if(mp.size() == cap) {
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }

        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */