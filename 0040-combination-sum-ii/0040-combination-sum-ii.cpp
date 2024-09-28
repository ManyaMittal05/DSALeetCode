class Solution {
public:
    void helper(vector<int> candidates, int i, int target, set<vector<int>>& st,
                vector<int> arr) {
        if (i >= candidates.size()) {
            if (target == 0) {
                st.insert(arr);
            }
            return;
        }

        helper(candidates, i+1, target, st, arr);

        if (target - candidates[i] >= 0) {
            arr.push_back(candidates[i]);
            helper(candidates, i + 1, target - candidates[i], st, arr);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> st;
        vector<int> arr;
        helper(candidates, 0, target, st, arr);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};