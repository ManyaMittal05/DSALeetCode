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

    char findKthBit(int n, int k) {
        vector<string> s(n+1);
        s[1] = "0";

        for(int i = 2; i < n + 1; i++){
            string invertedAndRev = invert(s[i-1]);
            s[i] = s[i-1] + "1" + invertedAndRev;
        }
        return s[n][k-1];
    }
};