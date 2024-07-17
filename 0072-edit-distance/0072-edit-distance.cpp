class Solution {
public:
//SPace Optimization using Tabulation 
//time - O(n*m)
//space - O(m);
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);

        //base cases of memoization
        for(int j = 0; j<=m; j++){
            prev[j] = j;
        }

        //exploring all possibilities
        for(int i = 1; i<=n; i++){
            curr[0] = i; //as 0th column of every row had value = i
            for(int j = 1; j<=m; j++){
                if(word1[i-1] == word2[j-1])
                    curr[j] = prev[j-1];
                else{
                    int insert = 1 + curr[j-1];
                    int del = 1 + prev[j];
                    int replace = 1 + prev[j-1];
                    curr[j] = min(insert, min(del, replace));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};