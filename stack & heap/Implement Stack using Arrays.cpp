struct stackData {
    vector<int> elements;
    int size;
    int capacity;
};
class myStack {
    stackData st;
  public:
    myStack(int n) {
        // Define Data Structures
        st.size = 0;
        st.capacity = n;
        st.elements.reserve(n);
    }

    bool isEmpty() {
        // check if the stack is empty
        if(st.size == 0) {
            return true;
        }
        
        return false;
    }

    bool isFull() {
        // check if the stack is full
        if(st.size == st.capacity) {
            return true;
        }
        
        return false;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(!isFull()) {
            st.elements.push_back(x);
            st.size++;
        }
    }

    void pop() {
        // removes an element from the top of the stack
        if(!isEmpty()){
            st.elements.pop_back();
            st.size--;
        }
    }

    int peek() {
        // Returns the top element of the stack
        if(!isEmpty()) {
            return st.elements.back();
        }
        
        return -1;
    }
};