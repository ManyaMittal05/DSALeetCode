class Solution {
public:
    
    int minimumPushes(string word) {
        vector<int> freq(26);
        int ans = 0;
        for(auto c : word){
            freq[c-'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        for(int i = 0; i<26; i++){
            if(i < 8){
                ans += freq[i];
            }
            else if(i >= 8 && i <= 15){
                ans += 2*freq[i];
            }
            else if(i >= 16 && i <= 23){
                ans += 3*freq[i];
            }
            else{
                ans += 4*freq[i];
            }
        }
        return ans;
    }
};