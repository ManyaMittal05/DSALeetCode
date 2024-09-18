class Solution {
public:
    long long helper(vector<int>& a, vector<int>& b, int i1, int i2, vector<vector<long long>>& dp){
        if(i1 >= a.size()) return 0;
        if(i2 >= b.size()) return -4e10;
        if(dp[i1][i2] != -1) return dp[i1][i2];

        long long pick = INT_MIN, notpick = INT_MIN;

        notpick = helper(a, b, i1, i2+1, dp);
        pick = (long long)a[i1] * b[i2] + helper(a, b, i1+1, i2+1, dp);

        return dp[i1][i2] =  max(pick, notpick);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {

        vector<vector<long long>> dp(4, vector<long long> (b.size(), -1));
        return helper(a, b, 0, 0, dp);
    }
};