class Solution {
public:
    void helper(string digits, int i, vector<string>& ans, string ds, unordered_map<int, string> mp){
        if(i >= digits.length()){
            if(ds != "")
                ans.push_back(ds);
            return;
        }

        int num = digits[i] - '0';
        string alpha = mp[num];

        for(int ind = 0; ind<alpha.length(); ind++){
            ds.push_back(alpha[ind]);
            helper(digits, i+1, ans, ds, mp);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        vector<string> ans;
        string ds;
        helper(digits, 0, ans, ds, mp);
        return ans;
    }
};