class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //using hash map
        int n = nums.size();
        int maj = n / 3;
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto [n , count] : mp){
            if(count > maj)
                ans.push_back(n);
            if(ans.size() == 2) break;
        }
        return ans;
    }
};