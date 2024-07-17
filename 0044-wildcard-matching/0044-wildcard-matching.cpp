class Solution {
public:

//Tabulation using memoization with 1 based indexing 
//time - O(n*m)
//space - O(n*m)
    
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));

        //base cases of memoization in tabulation
        for(int j = 1; j <= m; j++){
            int flag = 0;
            for(int k = 1; k<=j; k++){
                if(p[k-1] != '*'){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) dp[0][j] = true;
        }
        for(int i = 1; i<= n; i++){
            dp[i][0] = false;
        }
        dp[0][0] = true;

        //exploring all possibilities
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }

        return dp[n][m];
    }
};