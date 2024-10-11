class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);

        for(auto p : prerequisites){
            indegree[p[0]]++;
            adj[p[1]].push_back(p[0]);
        }

        queue<int> q;
        vector<int> ans;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int course = q.front();
            q.pop();
            ans.push_back(course);

            for(auto c : adj[course]){
                indegree[c]--;
                if(indegree[c] == 0)
                    q.push(c);
            }
        }

        if(ans.size() == numCourses) return ans;
        return {};
    }
};