class Solution {
public:
    void helper(vector<int> nums, vector<int> subsq, int i, vector<vector<int>>& ans){
        if(i >= nums.size()){
            ans.push_back(subsq);
            return;
        }

        helper(nums, subsq, i+1, ans);

        subsq.push_back(nums[i]);
        helper(nums, subsq, i+1, ans);
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subsq;
        int i = 0;
        helper(nums, subsq, i, ans);
        return ans;
    }
};