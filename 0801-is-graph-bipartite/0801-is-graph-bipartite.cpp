class Solution {
public:
    bool dfs(vector<vector<int>> graph, int node, vector<int>& visited,
             int color) {
        visited[node] = color;

        for (int i = 0; i < graph[node].size(); i++) {
            if (visited[graph[node][i]] == -1) {
                if (!dfs(graph, graph[node][i], visited, !color))
                    return false;
            } else if (visited[graph[node][i]] == color)
                return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> visited(v, -1);

        int color = 0;
        for (int i = 0; i < v; i++) {
            if (visited[i] == -1)
                if (!dfs(graph, i, visited, color))
                    return false;
        }
        return true;
    }
};