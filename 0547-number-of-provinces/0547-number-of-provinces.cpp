class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

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

                    for(int j = 0; j < isConnected[v].size(); j++){
                        if(!visited[j] && isConnected[v][j] == 1){
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return provinces;
    }
};