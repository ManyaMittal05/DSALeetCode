class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto edge : invocations){
            adj[edge[0]].push_back(edge[1]);
        }

        queue<int> q;
        q.push(k);
        unordered_set<int> sus;
        sus.insert(k);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i = 0; i < adj[node].size(); i++){
                if(sus.find(adj[node][i]) == sus.end()){
                    sus.insert(adj[node][i]);
                    q.push(adj[node][i]);
                }
            }
        }

        int initialSize = sus.size();

        for(auto method : invocations){
            if(sus.find(method[0]) == sus.end() &&
                    sus.find(method[1]) != sus.end()){
                sus.erase(method[1]);
                for(int i = 0; i < adj[method[1]].size(); i++){
                    if(sus.find(adj[method[1]][i]) != sus.end())
                        sus.erase(adj[method[1]][i]);
                }
            }
            else if(sus.find(method[0]) != sus.end() &&
                    sus.find(method[1]) == sus.end()){
                sus.erase(method[0]);
                for(int i = 0; i < adj[method[0]].size(); i++){
                    if(sus.find(adj[method[0]][i]) != sus.end())
                        sus.erase(adj[method[0]][i]);
                }
            }
        }

        int finalSize = sus.size();
        if(initialSize != finalSize) sus.clear();
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(sus.find(i) == sus.end())
                ans.push_back(i);
        }
        return ans;
    }
};