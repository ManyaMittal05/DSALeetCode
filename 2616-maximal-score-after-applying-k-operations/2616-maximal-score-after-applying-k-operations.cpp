class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int x : nums){
            pq.push(x);
        }

        long long score = 0;
        for(int i = 1; i <= k; i++){
            int ele = pq.top();
            pq.pop();
            score += ele;
            ele = ceil(ele / 3.0);
            pq.push(ele);
        }
        return score;
    }
};