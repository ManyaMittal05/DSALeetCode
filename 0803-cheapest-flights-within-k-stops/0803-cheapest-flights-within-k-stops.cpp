class Solution {
public:
    typedef pair<int, pair<int, int>> pipii; //{k, {stop, price}}
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<vector<pair<int, int>>> adj(n); //stop - {coonected stop, price}
        for(auto f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }   

        queue<pipii> q;
        q.push({0, {src, 0}});
        vector<int> price(n, INT_MAX);
        price[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            int kCount = it.first;
            int stop = it.second.first;
            int cost = it.second.second;
            q.pop();


            for(auto nextStopDetails : adj[stop]){
                int kCountOriginal = kCount;
                int nextStop = nextStopDetails.first;
                int nextCost = nextStopDetails.second + cost;
                if(nextStop != dest) kCountOriginal++;
                if(kCountOriginal <= k && nextCost < price[nextStop]){
                    price[nextStop] = nextCost;
                    q.push({kCountOriginal, {nextStop, nextCost}});
                }
            }
        }

        if(price[dest] == INT_MAX) return -1;
        return price[dest];
    }
};