class maxHeap {
  private:
    // Initialize your data members
    vector<int> heap;
    
    void swap(int el1, int el2) {
        int temp = heap[el1];
        heap[el1] = heap[el2];
        heap[el2] = temp;
    }

  public:

    void push(int x) {
        // Insert x into the heap
        heap.push_back(x);
        int curr_pos = heap.size() - 1;
        while(curr_pos > 0) {
            int parent_pos = (curr_pos - 1) / 2;
            if(heap[parent_pos] < heap[curr_pos]){
                swap(parent_pos, curr_pos);
                curr_pos = parent_pos;
            }
            else {
                break;
            }
        }
    }

    void pop() {
        // Remove the top (maximum) element
        if(heap.empty()) return;
        
        int top_pos = 0;
        int last_pos = heap.size() - 1;
        
        // swap top and last
        swap(top_pos, last_pos);
        
        heap.pop_back();
        
        int i = 0;
        while(true) {
            int child1 = 2 * i + 1;
            int child2 = 2 * i + 2;
            int isChild1 = child1 < heap.size();
            int isChild2 = child2 < heap.size();
            int largest = i;
            if(isChild1 && heap[child1] > heap[largest]){
                largest = child1;
            }
            if (isChild2 && heap[child2] > heap[largest]){
                largest = child2;
            }
            
            if(largest != i) {
                swap(largest ,i);
                i = largest;
            }
            else {
                break;
            }
        }
    }

    int peek() {
        // Return the top element or -1 if empty
        if(heap.empty()) return -1;
        return heap[0];
    }

    int size() {
        // Return the number of elements in the heap
        return heap.size();
    }
};