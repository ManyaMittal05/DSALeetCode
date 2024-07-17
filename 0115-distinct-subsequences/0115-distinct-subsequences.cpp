class Solution {
public:
//SPace Optimization using 1 based indexing
//time - O(n*m)
//space - O(m) 

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> prev(m+1, 0), curr(m+1, 0);

        //base cases of memoization
        prev[0] = 1, curr[0] = 1;
        //no need to write below base case as we have have already intialized array with 0
        // for(int j = 1; j <= m; j++){ //from j = 1 as dp[0][0] = 1
        //     prev[j] = 0;
        // }

        //exploring all possibilities
        for(int i = 1; i<= n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == t[j-1])
                    curr[j] = prev[j-1] + prev[j];
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        return (int)prev[m];
    }
};