class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> ans;
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        unordered_set<long long> set;
        minHeap.push(1);
        set.insert(1);
        
        while(ans.size() != n){
            long long ele = minHeap.top();
            ans.push_back(ele);
            minHeap.pop();

            if(set.find(ele*2) == set.end()){
                set.insert(ele*2);
                minHeap.push(ele*2);
            }
            if(set.find(ele*3) == set.end()){
                set.insert(ele*3);
                minHeap.push(ele*3);
            }
            if(set.find(ele*5) == set.end()){
                set.insert(ele*5);
                minHeap.push(ele*5);
            }
        }

        return ans.back();
    }
};