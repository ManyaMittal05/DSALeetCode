class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> directions = {{1,0}, {0,-1}, {0,1}, {-1,0}};
        queue<pair<int,int>> q;
        vector<vector<int>> ansImage = image;
        q.push({sr, sc});
        int startColor = image[sr][sc];

        if(startColor == color) return image;
        
        ansImage[sr][sc] = color;
        int m = image.size(), n= image[0].size();

        while(!q.empty()){
            pair<int,int> ele = q.front();
            int i = ele.first;
            int j = ele.second;
            q.pop();

            for(auto d : directions){
                int new_i = i + d[0];
                int new_j = j + d[1];

                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n
                        && ansImage[new_i][new_j] == startColor){
                    ansImage[new_i][new_j] = color;
                    q.push({new_i, new_j});
                }
            }
        }
        return ansImage;
    }
};