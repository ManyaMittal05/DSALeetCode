class Solution {
public:
    typedef long long ll;
    const int large_val = 2e9;
    typedef pair<long long, long long> P;

    ll Dijkstra(int n, vector<vector<int>>& edges, int source, int dest){
        unordered_map<ll, vector<pair<ll, ll>>> adj;
        for(auto& edge : edges){
            if(edge[2] != -1){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }

        priority_queue<P, vector<P>, greater<P>> pq;

        vector<ll> distance(n, INT_MAX);

        distance[source] = 0;
        pq.push({distance[source], source});

        while(!pq.empty()){
            ll currDist = pq.top().first;
            ll currNode = pq.top().second;
            pq.pop();

            for(auto &[nbr, wt] : adj[currNode]){

                if(currDist + wt < distance[nbr]){
                    distance[nbr] = currDist + wt;
                    pq.push({distance[nbr], nbr});
                }
            }
        }
        return distance[dest];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        //calculate the initial shortest path without considering -ve edge weights
        ll currShortestDist = Dijkstra(n, edges, source, destination);

        //no possible modifcation can result in shorter path
        if(currShortestDist < target){
            return {};
        }

        bool isMatchedTarget = (currShortestDist == target);

        //now thw last case is where shortest path > target
        //here we can modify the -ve edge weights to achieve the target value
        
        for(vector<int>& edge : edges){
            if(edge[2] == -1){
                edge[2] = (isMatchedTarget == true) ? large_val : 1;

                if(isMatchedTarget != true){
                    ll newShortestDist = Dijkstra(n, edges, source, destination);

                    if(newShortestDist <= target){
                        isMatchedTarget = true;
                        edge[2] += (target - newShortestDist);
                    }
                }
            }
        }

        if(isMatchedTarget == false)
            return {};

        return edges;
    }
};