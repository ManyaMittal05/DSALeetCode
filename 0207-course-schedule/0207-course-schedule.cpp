class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //using topo sort 
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto p : prerequisites){
            indegree[p[0]]++;
            adj[p[1]].push_back(p[0]);
        }

        queue<int> q;
        vector<int> topo;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int course = q.front();
            q.pop();
            topo.push_back(course);

            for(auto c : adj[course]){
                indegree[c]--;
                if(indegree[c] == 0)
                    q.push(c);
            }
        }

        if(numCourses == topo.size()) return true;
        return false;
    }
};