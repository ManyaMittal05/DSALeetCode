class compare{
    public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(auto num : nums){
            freq[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        for(auto [num, count] : freq){
            if(pq.size() < k){
                pq.push({num, count});
            }
            else{
                if(count > pq.top().second){
                    pq.pop();
                    pq.push({num, count});
                }
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        return ans;
    }
};