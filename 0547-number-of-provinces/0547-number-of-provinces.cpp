class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>> isConnected){
        visited[node] = true;
        for(int i=0; i<isConnected[node-1].size(); i++){
            if(isConnected[node-1][i] == 1){
                if(!visited[i+1]){
                    dfs(i+1, visited, isConnected);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> visited(n+1, false);
        for(int i = 1; i<n+1; i++){
            if(!visited[i]){
                dfs(i, visited, isConnected);
                count++;
            }
        }
        return count;
    }
};