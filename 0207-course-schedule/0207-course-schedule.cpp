class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        for(auto p : prerequisites){
            adj[p[0]].push_back(p[1]);
        }

        vector<int> in_degree(numCourses, 0);
        for(auto p : prerequisites){
            in_degree[p[1]]++;
        }

        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(in_degree[i] == 0)
                q.push(i);
        }

        vector<int> courseOrder;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            courseOrder.push_back(course);

            for(int i = 0; i<adj[course].size(); i++){
                in_degree[adj[course][i]]--;
                if(in_degree[adj[course][i]] == 0)
                    q.push(adj[course][i]);
            }
        }

        if(courseOrder.size() == numCourses) return true;
        return false;
    }
};