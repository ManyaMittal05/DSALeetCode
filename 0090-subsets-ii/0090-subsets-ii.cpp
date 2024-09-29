class Solution {
public:
    void helper(vector<int> nums, int index, vector<vector<int>>& ans,
                vector<int> ds) {
        
        ans.push_back(ds);

        for(int i = index; i<nums.size(); i++){
            if(i != index && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            helper(nums, i+1, ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        helper(nums, 0, ans, ds);
        return ans;
    }
};