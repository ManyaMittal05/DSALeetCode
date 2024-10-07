class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        
        for(int i = 0; i<s.length(); i++){
            if(st.empty()) st.push(s[i]);
            else{
                char ch = st.top();
                string check  = string() + ch + s[i];
                if(check == "AB" || check == "CD")
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        return st.size();
    }
};