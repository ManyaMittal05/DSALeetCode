class Solution {
public:
    static bool comp(pair<int,int> a, pair<int, int> b){
        if(a.second > b.second) return true;
        return false;
    }
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto ch : s){
            mp[ch] ++;
        }

        vector<pair<char, int>> freq;

        for(auto &it : mp){
            freq.push_back(it);
        }

        sort(freq.begin(), freq.end(), comp);
        string ans = "";
        for(int i = 0; i<freq.size(); i++){
            for(int j = 0; j<freq[i].second; j++){
                ans += freq[i].first;
            }
        }
        return ans;
    }
};