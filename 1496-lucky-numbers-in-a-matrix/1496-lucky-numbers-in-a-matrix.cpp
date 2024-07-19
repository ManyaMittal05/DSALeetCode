class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int nrows = matrix.size();
        int ncols = matrix[0].size();
        unordered_set<int> minInRows;
        vector<int> lucky;
        //finding min ele in all rows and inserting it into a set
        for(int i = 0; i<nrows; i++){
            int minEleInRow = INT_MAX;
            for(int j = 0; j<ncols; j++){
                minEleInRow = min(minEleInRow, matrix[i][j]);
            }
            minInRows.insert(minEleInRow);
        }

        //finding max ele in all columns
        for(int j = 0; j<ncols; j++){
            int maxEleInCol = 0;
            for(int i = 0; i<nrows; i++){
                maxEleInCol = max(maxEleInCol, matrix[i][j]);
            }
            if(minInRows.find(maxEleInCol) != minInRows.end())
                lucky.push_back(maxEleInCol);
        }

        return lucky;
    }
};