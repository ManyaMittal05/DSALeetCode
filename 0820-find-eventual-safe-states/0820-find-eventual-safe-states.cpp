class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> indegree(n);

        for(int i = 0 ; i < n; i++){
            for(auto node : graph[i]){
                indegree[i]++;
                revGraph[node].push_back(i);
            }
        }

        queue<int> q;
        vector<int> safe;
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for(auto i : revGraph[node]){
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};