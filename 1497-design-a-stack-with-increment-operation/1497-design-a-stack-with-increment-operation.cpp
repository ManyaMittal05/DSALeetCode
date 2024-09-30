class CustomStack {
    vector<int> arr;
    int capacity;
    int top;
    int size;
    vector<int> inc;
public:
    CustomStack(int maxSize) : arr(maxSize), inc(maxSize, 0) {
        capacity = maxSize;
        top = -1;
        size = 0;
    }
    
    void push(int x) {
        if(size == capacity) return;
        top++;
        arr[top] = x;
        size++;
    }
    
    int pop() {
        if(size == 0) return -1;
        int ele = arr[top] + inc[top];
        if(top > 0) inc[top-1] += inc[top];
        inc[top] = 0;
        top--;
        size--;
        return ele;
    }
    
    void increment(int k, int val) {
        if(size == 0) return;
        int range = min(k, size);
        inc[range-1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */