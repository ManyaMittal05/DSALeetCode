class Solution {
public:
    void bfs(int node, vector<bool>& visited, vector<vector<int>> isConnected){
        queue<int> q;
        visited[node] = true;
        q.push(node);

        while(!q.empty()){
            int vertex = q.front();
            q.pop();
            for(int i = 0; i<isConnected[vertex-1].size(); i++){
                if(isConnected[vertex-1][i] == 1){
                    if(!visited[i+1]){
                        visited[i+1] = true;
                        q.push(i+1);
                    }
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
                bfs(i, visited, isConnected);
                count++;
            }
        }
        return count;
    }
};