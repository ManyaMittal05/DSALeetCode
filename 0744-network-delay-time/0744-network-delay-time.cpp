class Solution {
public:
//taking n+1 because node numbering in the question starts from 1;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto t : times){
            adj[t[0]].push_back({t[1], t[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int> timeTrack(n+1, INT_MAX);
        timeTrack[0] = 0;
        timeTrack[k] = 0;

        while(!pq.empty()){
            auto p = pq.top();
            int time = p.first;
            int node = p.second;
            pq.pop();

            for(auto v : adj[node]){
                int nextNode = v.first;
                int nextTime = v.second + time;
                if(nextTime < timeTrack[nextNode]){
                    timeTrack[nextNode] = nextTime;
                    pq.push({nextTime, nextNode});
                }
            }
        } 

        int totalTime = *max_element(timeTrack.begin(), timeTrack.end());
        if(totalTime != INT_MAX) return totalTime;
        return -1;
    }
};