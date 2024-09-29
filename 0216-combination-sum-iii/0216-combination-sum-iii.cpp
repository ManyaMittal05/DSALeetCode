class Solution {
public:
    void helper(int k, int n, int num, int sum, vector<vector<int>>& ans, vector<int> ds){
        if(ds.size() == k && sum == n){
            ans.push_back(ds);
            return;
        }

        if(ds.size() == k && sum > n) return;

        for(int i = num; i<=9; i++){
            sum += i;
            ds.push_back(i);
            helper(k, n, i+1, sum, ans, ds);
            ds.pop_back();
            sum -= i;
        }
        
        
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(k, n, 1, 0, ans, ds);
        return ans;
    }
};