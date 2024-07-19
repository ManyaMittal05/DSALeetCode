class Solution {
public:
    //there will be only one lucky number
    //find max of all min elements in the row
    //find min of all max elements in column
    //if they are equal then the lucky number exits and return that number
    //else no lucky number exits
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int nrows = matrix.size();
        int ncols = matrix[0].size();
        vector<int> lucky;
        int maxMin = 0; //max of all min elements in the row
        int minMax = 1e9; //min of all max elements in the col

        //finding maxMin
        for(int i = 0; i<nrows; i++){
            int minEleInRow = INT_MAX;
            for(int j = 0; j<ncols; j++){
                minEleInRow = min(minEleInRow, matrix[i][j]);
            }
            maxMin = max(maxMin, minEleInRow);
        }

        //finding minMax
        for(int j = 0; j<ncols; j++){
            int maxEleInCol = 0;
            for(int i = 0; i<nrows; i++){
                maxEleInCol = max(maxEleInCol, matrix[i][j]);
            }
            minMax = min(minMax, maxEleInCol);
        }

        if(minMax == maxMin) lucky.push_back(minMax);
        return lucky;
    }
};