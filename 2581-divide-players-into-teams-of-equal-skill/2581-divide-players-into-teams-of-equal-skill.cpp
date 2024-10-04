class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = 0;
        int n = skill.size();
        if(n == 2) return(skill[0] * skill[1]);
        
        sort(skill.begin(), skill.end());

        for(int x : skill){
            sum += x;
        }

        int numOfPairs = n / 2;
        if(sum % numOfPairs != 0 ) return -1;
        int sumOfEachPair = sum / numOfPairs;

        vector<pair<int, int>> pairs;
        unordered_map<int, int> mp, freq;

        //finding freq of elements to handle duplicate pairs
        for(int x : skill)  
            freq[x]++;

        for(int i = 0; i<n; i++){
            if(mp.find(skill[i]) != mp.end()){
                if(freq[skill[i]] != freq[mp[skill[i]]])
                    return -1;
                else{
                    if(skill[i] == mp[skill[i]]) freq[skill[i]] /= 2;
                    for(int cnt = 1; cnt <= freq[skill[i]]; cnt++)
                        pairs.push_back({mp[skill[i]], skill[i]});
                    freq[skill[i]] = 0;
                }
                mp.erase(skill[i]);
            }
            else{
                int rem = sumOfEachPair - skill[i];
                mp[rem] = skill[i];
            }
        }

        if(pairs.size() != numOfPairs) return -1;

        long long ans = 0;
        for(auto p : pairs){
            ans += (p.first * p.second);
        }
        return ans;
    }
};