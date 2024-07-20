class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int nrows = rowSum.size();
        int ncols = colSum.size();
        vector<vector<int>> ans(nrows, vector<int> (ncols, 0));
        for(int i = 0; i<nrows; i++){
            for(int j = 0; j<ncols; j++){
                int minVal = min(rowSum[i], colSum[j]);
                ans[i][j] = minVal;
                rowSum[i] -= minVal;
                colSum[j] -= minVal;
            }
        }
        return ans;
    }
};