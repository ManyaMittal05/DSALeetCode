class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //using hash map
        int n = nums.size();
        int maj = n / 3 + 1;
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
            if(mp[nums[i]] == maj)
                ans.push_back(nums[i]);
            if(ans.size() == 2) break;
        }
        
        return ans;
    }
};