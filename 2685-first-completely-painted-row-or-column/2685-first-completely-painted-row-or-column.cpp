class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> mp;
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mp[mat[i][j]] = {i, j};
            }
        }

        vector<int> rows(m, n), cols(n, m);

        for(int i = 0; i< arr.size(); i++){
            rows[mp[arr[i]].first]--;
            cols[mp[arr[i]].second]--;

            if(rows[mp[arr[i]].first] == 0 || cols[mp[arr[i]].second] == 0) 
                return i;
        }
        return -1;
    }
};