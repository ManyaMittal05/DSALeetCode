class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        if(k == num.size()) return "0";

        for(int i = 0; i<num.size(); i++){
            if(st.empty()) st.push(num[i]);
            else{
                while(k > 0 && !st.empty() && st.top() > num[i]){
                    st.pop();
                    k--;
                }
                if(st.empty()){
                    if(num[i] != '0')
                        st.push(num[i]);
                }
                else{
                    st.push(num[i]);
                }
            }
        }

        //if k!=0, then remove from the last i.e. the stack's top until k==0
        while(!st.empty() && k != 0){
            st.pop();
            k--;
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        int countZeros = 0;
        for(int i = ans.size()-1; i >= 0; i--){
            if(ans[i] == '0')
                countZeros++;
            else 
                break;
        }

        reverse(ans.begin(), ans.end());
        ans = ans.substr(countZeros, ans.size() - countZeros);
        if(ans.size() == 0) return "0";
        return ans;
    }
};