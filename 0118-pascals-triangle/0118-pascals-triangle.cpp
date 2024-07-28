class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i<numRows; i++){
            int rowNum = i + 1;
            int ele = 1;
            vector<int> row;
            row.push_back(ele);
            for(int j = 1; j<rowNum; j++){
                ele = ele * (rowNum - j);
                ele = ele / j;
                row.push_back(ele);
            }
            ans.push_back(row);
        }
        return ans;
    }
};