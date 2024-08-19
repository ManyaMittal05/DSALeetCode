class Solution {
    //recursive solution
public:
    int solve(int n, int currA, int clipA, vector<vector<int>>& dp) {
        if (currA == n) {
            return 0;
        }

        if(currA > n){
            return 1e7;
        }

        if(dp[currA][clipA] != -1) return dp[currA][clipA];

        // Copy and paste operation
        int copyPaste = 1 + 1 + solve(n, currA + currA, currA, dp);

        //no copy, only paste
        int paste = 1 + solve(n, currA + clipA, clipA, dp);

        return dp[currA][clipA] = min(copyPaste, paste);
    }

    int minSteps(int n) {
        if(n == 1 ) return 0;

        vector<vector<int>> dp(n, vector<int> (n, -1));
        int currA = 1, clipA = 1;
        return 1 + solve(n, currA, clipA, dp);
    }
};