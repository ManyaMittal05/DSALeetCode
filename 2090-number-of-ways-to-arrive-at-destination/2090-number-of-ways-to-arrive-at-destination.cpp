class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        vector<long long> time(n, LLONG_MAX);
        vector<int> ways(n, 0);
        ways[0] = 1;
        time[0] = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        pq.push({0, 0}); // time, node

        while (!pq.empty()) {
            auto it = pq.top();
            long long t = it.first;
            int node = it.second;
            pq.pop();

            for (auto neighbour : adj[node]) {
                int nextNode = neighbour.first;
                long long newtime = t + neighbour.second;

                if (newtime < time[nextNode]) {
                    pq.push({newtime, nextNode});
                    time[nextNode] = newtime;
                    ways[nextNode] = ways[node];
                } else if (newtime == time[nextNode]) {
                    ways[nextNode] = (ways[nextNode] + ways[node]) % 1000000007;
                }
            }
        }
        return ways[n - 1] % 1000000007;
    }
};