class CustomStack {
    int* arr;
    int capacity;
    int top;
    int size;
public:
    CustomStack(int maxSize) {
        capacity = maxSize;
        top = -1;
        size = 0;
        arr = new int[capacity];
    }
    
    void push(int x) {
        if(size == capacity) return;
        top++;
        arr[top] = x;
        size++;
    }
    
    int pop() {
        if(size == 0) return -1;
        int ele = arr[top];
        top--;
        size--;
        return ele;
    }
    
    void increment(int k, int val) {
        int range = min(k, size);
        for(int i = 0; i<range; i++){
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */