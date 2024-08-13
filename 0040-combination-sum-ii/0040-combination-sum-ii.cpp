class Solution {
public:
    void solve(vector<int>& c, int index, int target, vector<int>& comb, vector<vector<int>>& ans ){
        if(target == 0){
            ans.push_back(comb);
            return;
        }

        for(int i = index; i<c.size(); i++){
            if(i > index && c[i] == c[i-1]) continue;
            if(c[i] > target) break;
            comb.push_back(c[i]);
            solve(c, i+1, target - c[i], comb, ans);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        solve(candidates, 0, target, comb, ans);
        return ans;
    }
};