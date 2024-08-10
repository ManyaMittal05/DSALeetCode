class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int color, int i, vector<int>& visited){
        visited[i] = color;

        for(auto g : graph[i]){
            if(visited[g] == -1){
                if(!dfs(graph, !color, g, visited)) return false;;
            }
            else if(visited[g] == color){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);

        for(int i = 0; i<n; i++){
            if(visited[i] == -1){
                if(!dfs(graph, 0, i, visited)) 
                    return false;
            }
        }
        return true;
    }
};