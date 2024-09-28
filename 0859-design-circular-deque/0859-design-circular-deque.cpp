class MyCircularDeque {
    int* deq;
    int k, front, rear, size;
public:
    MyCircularDeque(int k) {
        this->k = k;
        front = 0;
        rear = k-1;
        size = 0;
        deq = new int[k];
    }
    
    bool insertFront(int value) {
        if(size == k) 
            return false;
        front = (front == 0) ? k-1 : front - 1;
        deq[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size == k)
            return false;
        rear = (rear == k-1) ? 0 : rear + 1;
        deq[rear] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size == 0)
            return false;
        front = (front == k-1) ? 0 : front + 1;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(size == 0) 
            return false;
        rear = (rear == 0) ? k - 1 : rear - 1;
        size--;
        return true;
    }
    
    int getFront() {
        if(size == 0)
            return -1;
        return deq[front];
    }
    
    int getRear() {
        if(size == 0)
            return -1;
        return deq[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */