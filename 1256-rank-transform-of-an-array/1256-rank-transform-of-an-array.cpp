class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> dup = arr;
        sort(dup.begin(), dup.end());
        unordered_map<int,int> mp;
        int rank = 1;
        for(int i = 0; i<dup.size(); i++){
            if(mp.find(dup[i]) == mp.end()){
                mp[dup[i]] = rank++;
            }
        }

        for(int i = 0; i<arr.size(); i++){
            dup[i] = mp[arr[i]];
        }
        return dup;
    }
};