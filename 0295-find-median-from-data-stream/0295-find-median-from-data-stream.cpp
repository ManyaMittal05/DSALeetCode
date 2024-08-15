class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median = -1;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //if the size of both heaps is equal that means 
        //that the new num will make the number of elements odd
        //hence if the new num is greater than the median,
        //it will go to right side, i.e. the min heap
        //else if the new num is smaller than the median,
        //it will go to the left side, i.e. the  max heap
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

        //now if the size of the maxHeap(left to median) > size of minHeap(right to median)
        //this means, the current number of elements is odd and
        //new num's addition will make number of elements even
        //so median will be avg of top of maxHeap & minHeap (rightmost ele of left side & leftmost ele of right side)
        //if new num is greater than the median, it will go to the right (minHeap)
        //Since minHeap's size is smaller, we will directly add the new num into it
        //but if the new num is smaller than the median, it has to be added in left(maxHeap)
        //but since the size of maxHeap is greater than the minHeap
        //we cannot add it directly into the maxHeap because
        //difference between the size of both heaps should not exceed 1 otherwise their tops will not give us median
        //so we will pop the top element of maxHeap and put it in the minHeap
        //now sizes of minHeap is greater than maxHeap by 1
        //so now we can put the new num in the maxHeap
        //now size of both the heaps is equal thus median = avg of their top elements
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

        //now if the size of the minHeap(right to median) > size of maxHeap(left to median)
        //this means, the current number of elements is odd and
        //new num's addition will make number of elements even
        //so median will be avg of top of maxHeap & minHeap (rightmost ele of left side & leftmost ele of right side)
        //if new num is smaller than the median, it will go to the left (maxHeap)
        //Since maxHeap's size is smaller, we will directly add the new num into it
        //but if the new num is greater than the median, it has to be added in right(minHeap)
        //but since the size of minHeap is greater than the maxHeap
        //we cannot add it directly into the minHeap because
        //difference between the size of both heaps should not exceed 1 otherwise their tops will not give us median
        //so we will pop the top element of minHeap and put it in the maxHeap
        //now sizes of maxHeap is greater than minHeap by 1
        //so now we can put the new num in the minHeap
        //now size of both the heaps is equal thus median = avg of their top elements
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