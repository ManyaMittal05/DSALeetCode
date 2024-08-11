class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<vector<int>> reversedGraph(v);
        vector<int> indegree(v);
        for(int i = 0; i<v; i++){
            for(int j = 0; j<graph[i].size(); j++){
                reversedGraph[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i<v; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> order;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);

            for(int i = 0; i<reversedGraph[node].size(); i++){
                indegree[reversedGraph[node][i]]--;
                if(indegree[reversedGraph[node][i]] == 0)
                    q.push(reversedGraph[node][i]);
            }
        }

        sort(order.begin(), order.end());
        return order;
    }
};