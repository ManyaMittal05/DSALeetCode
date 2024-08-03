class Solution {
public:
    bool solve(string s, unordered_set<string>& dict, int len, int ind, vector<int>& dp){
        if(ind >= s.length())
            return true;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        if(dict.find(s) != dict.end())
            return true;

        for(int l = 1; l <= s.length(); l++){
            string temp = s.substr(ind, l);
            if(dict.find(temp) != dict.end() && solve(s, dict, len, ind+l, dp))
                return dp[ind] = true;
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto& word : wordDict){
            dict.insert(word);
        }
        int n = s.length();
        vector<int> dp(n, -1); 
        return solve(s, dict, 0, 0, dp);
    }
};