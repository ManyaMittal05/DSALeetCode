class Solution {
public:
    string makeFancyString(string s) {
        char ch = s[0];
        int count = 1;
        string ans = "";
        ans += s[0];
        for(int i = 1; i<s.size(); i++){
            if(ch == s[i]){
                count++;
            }
            else{
                ch = s[i];
                count = 1;
            }
            if(count < 3){
                ans += s[i];
            }
        }
        return ans;
    }
};