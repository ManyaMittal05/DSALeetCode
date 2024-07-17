class Solution {
public:
//Tabulation using 1 based indexing
//time - O(n*m)
//space - O(n*m) 

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n+1, vector<double> (m+1, 0));

        //base cases of memoization
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        //no need to write below base case as we have have already intialized array with 0
        // for(int j = 1; j <= m; j++){ //from j = 1 as dp[0][0] = 1
        //     dp[0][j] = 0;
        // }

        //exploring all possibilities
        for(int i = 1; i<= n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }
};