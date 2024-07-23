class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(int n : nums){
            mp[n]++;
        }

        vector<pair<int, int>> vec;
        for(auto [val ,count] : mp){
            vec.push_back({val , count});
        }

        sort(vec.begin(), vec.end(), [&](pair<int,int> a, pair<int,int> b){
            if(a.second < b.second) return true;
            else if(a.second > b.second) return false;
            else{
                if(a.first > b.first) return true;
                return false;
            }
        });

        int i = 0;
        for(int j = 0; j < vec.size(); j++){
            for(int k = 0; k<vec[j].second; k++){
                nums[i] = vec[j].first;
                i++;
            }
        }

        return nums;
    }
};