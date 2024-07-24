class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int startRow = 0, endRow = m-1, startCol = 0, endCol = n-1;
        int count = 0;
        int totalElements = n*m;
        vector<int> ans;

        while(count < totalElements){
            for(int i = startCol; count < totalElements && i<=endCol; i++){
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;

            for(int i = startRow; count < totalElements && i<=endRow; i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            for(int i = endCol; count < totalElements && i>=startCol; i--){
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;

            for(int i = endRow; count < totalElements && i>=startRow; i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};