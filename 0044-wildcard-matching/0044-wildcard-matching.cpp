class Solution {
public:

//SPace Optimization using Tabulation
//time - O(n*m)
//space - O(m)
    
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<bool> prev(m+1, false), curr(m+1, false);

        //base cases of memoization in tabulation
        for(int j = 1; j <= m; j++){
            int flag = 0;
            for(int k = 1; k<=j; k++){
                if(p[k-1] != '*'){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                prev[j] = true;
                curr[j] = true;
            } 
        }
    
        prev[0] = true;
        curr[0] = true;

        //exploring all possibilities
        for(int i = 1; i<=n; i++){
            curr[0] = false; //for every row for which i > 0, j = 0 in tabulation
            for(int j = 1; j<=m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    curr[j] = prev[j-1];
                else if(p[j-1] == '*')
                    curr[j] = prev[j] || curr[j-1];
                else curr[j] = false;
            }
            prev = curr;
        }

        return curr[m];
    }
};