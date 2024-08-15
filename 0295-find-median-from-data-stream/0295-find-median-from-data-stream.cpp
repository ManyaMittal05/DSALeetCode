class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median = -1;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size() == minHeap.size()){
            if(num > median){
                minHeap.push(num);
                median = minHeap.top();
            }
            else{
                maxHeap.push(num);
                median = maxHeap.top();
            }
        }
        else if(maxHeap.size() > minHeap.size()){
            if(num > median){
                minHeap.push(num);
                median = (double)(maxHeap.top() + minHeap.top())/2.0;
            }
            else{
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
                median = (double)(maxHeap.top() + minHeap.top())/2.0;
            }
        }
        else{
            if(num > median){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
                median = (double)(maxHeap.top() + minHeap.top())/2.0;
            }
            else{
                maxHeap.push(num);
                median = (double)(maxHeap.top() + minHeap.top())/2.0;
            }
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */