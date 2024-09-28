class Solution {
public:
    void helper(vector<int>& candidates, int i, int target,
                vector<vector<int>>& ans, vector<int>& arr) {
        if (target == 0) {
            ans.push_back(arr);
            return;
        }

        for (int index = i; index < candidates.size(); index++) {
            if (index > i && candidates[index] == candidates[index - 1])
                continue;
            if (candidates[index] > target)
                break;
            arr.push_back(candidates[index]);
            helper(candidates, index + 1, target - candidates[index], ans, arr);
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> arr;
        helper(candidates, 0, target, ans, arr);
        return ans;
    }
};