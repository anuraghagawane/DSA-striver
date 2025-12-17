struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    int cnt;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        prev = NULL;
        next = NULL;
        cnt = 1;
    }
};

struct List {
    int size = 0;
    Node* head;
    Node* tail;

    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* node) {
        Node* temp = head -> next;
        node -> prev = head;
        node -> next = temp;
        temp -> prev = node;
        head -> next = node;
        size++;
    }

    void delNode(Node* node) {
        node->prev->next = node -> next;
        node->next-> prev = node -> prev;
        size--;
    }
};


class LFUCache {
    int capacity;
    int size;
    int minFreq;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        minFreq = 0;
    }

    void updateList(Node* node) {
        int cnt = node -> cnt;
        int key = node -> key;

        keyNode.erase(key);
        freqList[cnt]->delNode(node);

        if(freqList[cnt]->size == 0 && minFreq == cnt) {
            minFreq++;
        }

        cnt++;

        List* nextFreqList = new List();

        if(freqList.find(cnt) != freqList.end()) {
            nextFreqList = freqList[cnt];
        }
        node->cnt = cnt;
        nextFreqList->addNode(node);
        freqList[cnt] = nextFreqList;//check by removing
        keyNode[key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* f = keyNode[key];
            updateList(f);
            return f->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyNode.find(key) != keyNode.end()){
            Node* f = keyNode[key];
            f -> value = value;
            updateList(f);
        }
        else {
            if(size == capacity) {
                List* last = freqList[minFreq];
                Node* lastNode = last->tail->prev;

                last->delNode(lastNode);
                keyNode.erase(lastNode->key);
                size--;
            }
            size++;
            Node* node = new Node(key, value);
            List* nextList = new List();
            int cnt = 1;
            if(freqList.find(cnt) != freqList.end()) {
                nextList = freqList[cnt];
            }

            minFreq = 1;
            nextList->addNode(node);
            freqList[cnt] = nextList;
            keyNode[key] = node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */