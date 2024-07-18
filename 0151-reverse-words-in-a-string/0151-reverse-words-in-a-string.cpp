class Solution {
public:
    string reverseWords(string s) {
        int i = 0; 
        int n = s.size();
        while(i<n && s[i] == ' ') i++;

        stack<string> st;
        string str = "";
        while(i < n){
            if(s[i] == ' '){
                if(str.length() != 0) st.push(str);
                str = "";
            }
            else{
                str += s[i];
            }
            i++;
        }

        if(str.length() != 0) st.push(str);
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            if(st.size() > 1) ans += " ";
            st.pop();
        } 
        return ans;
    }
};