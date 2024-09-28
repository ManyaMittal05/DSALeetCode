class Solution {
public:
    void helper(int i, vector<int> nums, int target, vector<vector<int>>& ans,
                vector<int> output) {
        if (i >= nums.size()) {
            if (target == 0) {
                ans.push_back(output);
            }
            return;
        }

        helper(i+1, nums, target, ans, output);

        if(target - nums[i] >= 0){
            output.push_back(nums[i]);
            helper(i, nums, target - nums[i], ans, output);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        helper(0, candidates, target, ans, output);
        return ans;
    }
};