class compare{
    public:
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
        return a.first > b.first;
    }
};

class Solution {
public:

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;

        auto hash_pair = [](const pair<int, int>& p){
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        };

        unordered_set<pair<int,int>, decltype (hash_pair)> set(0, hash_pair);

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
            compare> pq;

        pq.push({nums1[0] + nums2[0], {0, 0}});

        while(k > 0 && !pq.empty()){
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            pair<int, int> indices = p.second;
            int i = indices.first;
            int j = indices.second;

            result.push_back({nums1[i], nums2[j]});
            k--;

            if(i + 1 < nums1.size()){
                if(set.find({i+1, j}) == set.end()){
                    set.insert({i+1, j});
                    pq.push({nums1[i+1] + nums2[j], {i+1, j}});
                }
            }

            if(j + 1 < nums2.size()){
                if(set.find({i, j+1}) == set.end()){
                    set.insert({i, j+1});
                    pq.push({nums1[i] + nums2[j+1], {i, j+1}});
                }
            }
        }

        return result;
    }
};