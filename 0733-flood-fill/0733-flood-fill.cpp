class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    void dfs(vector<vector<int>>& image, int i, int j, int color, int initialCol, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n || image[i][j] != initialCol)
            return;
        
        image[i][j] = color;
        for(auto d : dir){
            int new_i = i + d[0];
            int new_j = j + d[1];

            dfs(image, new_i, new_j, color, initialCol, m, n);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ansGrid = image;
        int initialColor = image[sr][sc];
        if(initialColor == color) return image;

        int m = image.size();
        int n = image[0].size();

        dfs(ansGrid, sr, sc, color, initialColor, m, n);
        return ansGrid;
    }
};