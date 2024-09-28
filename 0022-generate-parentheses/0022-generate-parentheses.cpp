class Solution {
public:
    void helper(int close, int open, string s, vector<string>& ans){
        if(open == 0 && close == 0){
            ans.push_back(s);
            return;
        }

        if(open == close){
            s.push_back('(');
            helper(close, open-1, s, ans);
        }
        else if(open == 0){
            s += ')';
            helper(close-1, open, s, ans);
        }
        else if(close == 0){
            s += '(';
            helper(close, open-1, s, ans);
        }
        else{
            string s1 = s;
            s1 += '(';
            helper(close, open-1, s1, ans);
            string s2 = s;
            s2 += ')';
            helper(close-1, open, s2, ans);
        }


    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        helper(n, n, s, ans);
        return ans;
    }
};