class Solution {
public:
    bool isPalindrome(string s){
        int n = s.length();
        for(int i = 0; i<n/2; i++){
            if(s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }

    void helper(string s, int index, vector<vector<string>>& ans, vector<string> ds){
        if(index >= s.length()){
            ans.push_back(ds);
            return;
        }

        for(int i = index; i<s.length(); i++){
            string substr = s.substr(0, i+1);
            if(isPalindrome(substr)){
                ds.push_back(substr);
                string new_s = s.substr(i+1);
                helper(new_s, 0, ans, ds);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        helper(s, 0, ans, ds);
        return ans;
    }
};