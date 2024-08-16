class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int, int>> mini, maxi;
        int diff = INT_MIN;
        for(int i=0; i<arrays.size(); i++){
            mini.push_back({arrays[i][0], i});
            maxi.push_back({arrays[i][arrays[i].size()-1], i});
        }
        int n = arrays.size();
        sort(mini.begin(), mini.end());
        sort(maxi.begin(), maxi.end());
        
        if(mini[0].second != maxi[n-1].second){
            diff = maxi[n-1].first - mini[0].first;
        }
        else{
            int d1 = maxi[n-2].first - mini[0].first;
            int d2 = maxi[n-1].first - mini[1].first;
            diff = max(d1, d2);
        }
        return diff;
    }
};