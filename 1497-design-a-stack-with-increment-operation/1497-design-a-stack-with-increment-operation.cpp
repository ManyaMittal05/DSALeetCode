class CustomStack {
    vector<int> arr;
    int capacity;
    int top;
    vector<int> inc;
public:
    CustomStack(int maxSize) : arr(maxSize), inc(maxSize, 0) {
        capacity = maxSize;
        top = -1;
    }
    
    void push(int x) {
        if(top == capacity-1) return;
        top++;
        arr[top] = x;
    }
    
    int pop() {
        if(top == -1) return -1;
        int ele = arr[top] + inc[top];
        if(top > 0) inc[top-1] += inc[top];
        inc[top] = 0;
        top--;
        return ele;
    }
    
    void increment(int k, int val) {
        if(top == -1) return;
        int range = min(k-1, top);
        inc[range] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */