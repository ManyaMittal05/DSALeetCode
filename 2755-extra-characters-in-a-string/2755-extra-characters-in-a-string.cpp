class Solution {
public:
    //memoization
    int solve(string s, int &n, unordered_set<string> set, int i, vector<int>& dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        //considering s[i] as an extra character
        int result = 1 + solve(s, n, set, i+1, dp);

        //considering s[i] not as extra character
        for(int j = i; j < n; j++){
            string substring = s.substr(i, j - i + 1);
            if(set.find(substring) != set.end()){
                result = min(result, solve(s, n, set, j+1, dp));
            }
        }
        return dp[i] = result;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        unordered_set<string> set(dictionary.begin(), dictionary.end());

        vector<int> dp(n , -1);
        return solve(s, n, set, 0, dp);
    }
};