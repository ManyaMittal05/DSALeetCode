class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int nrows = rowSum.size();
        int ncols = colSum.size();
        vector<vector<int>> ans(nrows, vector<int> (ncols, 0));
        int i = 0, j = 0;

        while(i < nrows && j < ncols){
            int minVal  = min(rowSum[i], colSum[j]);
            ans[i][j] = minVal;
            rowSum[i] -= minVal;
            colSum[j] -= minVal;
            
            if(rowSum[i] == 0) i++;
            if(colSum[j] == 0) j++;
        }
        return ans;
    }
};