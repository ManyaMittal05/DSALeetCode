class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i<n; i++){
            for(int j =  0; j < n; j++){
                if(isConnected[i][j] == 1 && j != i){
                    adj[i].push_back(j);
                }
            }
        }

        queue<int> q;
        vector<int> visited(n, false);
        int provinces = 0;

        for(int i = 0; i<n; i++){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                provinces++;

                while(!q.empty()){
                    int v = q.front();
                    q.pop();

                    for(int j = 0; j < adj[v].size(); j++){
                        if(!visited[adj[v][j]]){
                            visited[adj[v][j]] = true;
                            q.push(adj[v][j]);
                        }
                    }
                }
            }
        }
        return provinces;
    }
};