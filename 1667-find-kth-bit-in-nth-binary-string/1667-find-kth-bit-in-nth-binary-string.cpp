class Solution {
public:
    string invert(string s){
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
        reverse(s.begin(), s.end());
        return s;
    }

    string helper(int n){
        if(n == 1)
            return "0";
        
        string prevStr = helper(n - 1);

        return prevStr + "1" + invert(prevStr);
    }

    char findKthBit(int n, int k) {
        string s = helper(n);
        return s[k-1];
    }
};