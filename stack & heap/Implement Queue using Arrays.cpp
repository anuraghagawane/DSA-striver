class myQueue {
    int capacity;
    int size;
    int front;
    int back;
    int* q;
  public:
    myQueue(int n) {
        // Define Data Structures
        capacity = n;
        size = 0;
        front = 0;
        back = -1;
        q = new int[capacity];
    }

    bool isEmpty() {
        // check if the queue is empty
        return size == 0;
    }

    bool isFull() {
        // check if the queue is full
        return size == capacity;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull()) return;
        back = (back + 1) % capacity;
        
        q[back] = x;
        size++;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty()) return;
        front = (front+1) % capacity;
        size--;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty()) return -1;
        return q[front];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty()) return -1;
        return q[back];
    }
};