class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i = 0; i < dominoes.size(); i++){

            int a = dominoes[i][0], b = dominoes[i][1];
            int num = min(a, b) + 10 * max(a, b);
            if(mp[num] > 0) ans += mp[num];
            mp[num]++;
        }
        return ans;
    }
};