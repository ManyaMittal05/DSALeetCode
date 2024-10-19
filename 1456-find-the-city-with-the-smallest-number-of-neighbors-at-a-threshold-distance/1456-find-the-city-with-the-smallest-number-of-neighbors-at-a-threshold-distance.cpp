class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMat(n, vector<int> (n, 1e9));
        
        for(int i = 0; i < n; i++){
            adjMat[i][i] = 0;
        }

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adjMat[u][v] = wt;
            adjMat[v][u] = wt;
        }

        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][via] + adjMat[via][j]);
                }
            }
        }

        vector<int> count(n, 0);
        int minCount = 1e9;
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(adjMat[i][j] <= distanceThreshold && i != j){
                    count[i]++;
                }
            }
            if(count[i] <= minCount){
                minCount = count[i];
                ans = i;
            }
        }
        return ans;
    }
};