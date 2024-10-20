class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> st;
        int n = exp.size();
        
        for(int i = n - 1; i >= 0; i--){
            if(exp[i] == '|'){
                bool ans = false;
                while(st.top() != ')'){
                    if(st.top() == 't'){
                        ans |= true;
                    }
                    else if(st.top() == 'f'){
                        ans |= false;
                    }
                    st.pop();
                }
                st.pop();
                if(ans) st.push('t');
                else st.push('f');
            }

            else if(exp[i] == '&'){
                bool ans = true;
                while(st.top() != ')'){
                    if(st.top() == 't'){
                        ans &= true;
                    }
                    else if(st.top() == 'f'){
                        ans &= false;
                    }
                    st.pop();
                }
                st.pop();
                if(ans) st.push('t');
                else st.push('f');
            }

            else if(exp[i] == '!'){
                bool ans;
                while(st.top() != ')'){
                    if(st.top() == 't'){
                        ans = false;
                    }
                    else if(st.top() == 'f'){
                        ans = true;
                    }
                    st.pop();
                }
                st.pop();
                if(ans) st.push('t');
                else st.push('f');
            }

            else{
                st.push(exp[i]);
            }
        }
        
        if(st.top() == 't') return true;
        return false;
    }
};