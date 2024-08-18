class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size();
        int cols = points[0].size();
        vector<long long> prev(cols);

        for(int j = 0; j<cols; j++){
            prev[j] = points[0][j];
        }

        for(int i = 1; i<rows; i++){
            vector<long long> left(cols, 0);
            vector<long long> right(cols, 0);

            left[0] = prev[0];
            for(int j = 1; j<cols; j++){
                left[j] = max(prev[j], left[j-1]-1);
            }

            right[cols-1] = prev[cols-1];
            for(int j = cols-2; j >= 0; j--){
                right[j] = max(prev[j], right[j+1]-1);
            }

            vector<long long> curr(cols, 0);
            for(int j = 0; j<cols; j++){
                curr[j] = points[i][j] + max(left[j], right[j]);
            }
            
            prev = curr;
        }

        return *max_element(prev.begin(), prev.end());


    }
};