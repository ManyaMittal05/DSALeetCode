class Solution {
public:
//Memoization
    int solve(string s, int l, int r, vector<vector<int>>& dp){
        if(l == r){
            return 1;
        }

        if(l > r){
            return 0;
        }

        if(dp[l][r] != -1) return dp[l][r];

        int i = l+1;
        while(s[i] == s[l]){
            i++;
        }
        if(i == r+1){
            return 1;
        }

        int basic = 1 + solve(s, i, r, dp);
        int greed = INT_MAX;
        for(int j = i; j<=r; j++){
            if(s[j] == s[l]){
                int ans = solve(s, i, j-1, dp) + solve(s, j, r, dp);
                greed = min(greed, ans);
            }
        }

        return dp[l][r] = min(basic, greed);
    }

    int strangePrinter(string s) {
        int n = s.length();
        int l = 0, r = n-1;
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(s, l, r, dp);
    }
};