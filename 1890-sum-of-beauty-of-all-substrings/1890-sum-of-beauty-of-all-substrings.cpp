class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        for(int i = 0; i<s.size(); i++){
            unordered_map<char, int> mp;
            for(int j = i; j<s.size(); j++){
                //counting freq of each character
                mp[s[j]]++;
                int leastFreq = INT_MAX;
                int mostFreq = INT_MIN;

                //finding least and most freq character uptil now
                for(auto [ch, freq] : mp){
                    leastFreq = min(leastFreq, freq);
                    mostFreq = max(mostFreq, freq);
                }
                sum += mostFreq - leastFreq;
            }
        }
        return sum;
    }
};