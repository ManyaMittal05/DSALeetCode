class Solution {
public:
    int maxOperations(string s) {
        int end = s.length();
        
        int j = 0, count = 0, op = 0;
        for(int i = end; i>=0; i--){
            if(i > 0 && s[i] == '0' && s[i-1] == '1') count++;
            if(s[i] == '1') op += count;
        }
        return op;
    }
};