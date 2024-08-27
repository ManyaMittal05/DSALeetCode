class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        int i = 0;
        for(auto e : edges){
            adj[e[0]].push_back({e[1], succProb[i]});
            adj[e[1]].push_back({e[0], succProb[i]});
            i++;
        }

        priority_queue<pair<double, int>> maxHeap;
        vector<double> probability(n, 0);
        maxHeap.push({1.0, start_node});
        probability[start_node] = 1;

        while(!maxHeap.empty()){
            pair<double, int> p = maxHeap.top();
            int node = p.second;
            double prob = p.first;
            maxHeap.pop();

            for(int i = 0; i<adj[node].size(); i++){
                double probab = adj[node][i].second;
                int adjNode = adj[node][i].first;

                if(probab * prob > probability[adjNode]){
                    probability[adjNode] = probab * prob;
                    maxHeap.push({probability[adjNode], adjNode});
                }
            }
        }

        return probability[end_node];
    }
};