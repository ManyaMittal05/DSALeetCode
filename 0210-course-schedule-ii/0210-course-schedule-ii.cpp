class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto p : prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> courseOrder;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            courseOrder.push_back(node);

            for(int i = 0; i<adj[node].size(); i++){
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                }
            }
        }

        if(courseOrder.size() == numCourses){
            return courseOrder;
        }
        return {};
    }
};