class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {0,-1}, {0,1}, {-1,0}};

    void dfs(vector<vector<int>>& image, int i, int j, int color, int startColor){
        image[i][j] = color;

        for(auto d : directions){
            int new_i = i + d[0];
            int new_j = j + d[1];

            if(new_i >= 0 && new_i < image.size() && new_j >= 0 && new_j < image[0].size()
                    && image[new_i][new_j] == startColor){
                image[new_i][new_j] = color;
                dfs(image, new_i, new_j, color, startColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ansImage = image;
        
        int startColor = image[sr][sc];
        if(startColor == color) return image;

        dfs(ansImage, sr, sc, color, startColor);
        return ansImage;
    }
};