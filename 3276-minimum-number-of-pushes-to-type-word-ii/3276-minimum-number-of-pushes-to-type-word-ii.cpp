class Solution {
public:
    static bool comp(pair<char,int> a, pair<char,int> b){
        if(a.second > b.second) return true;
        return false;
    }
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        int countLetters = 0;
        int ans = 0;
        for(int i = 0; i<word.size(); i++){
            if(freq[word[i]-'a'] == 0){
                countLetters++;
            }
            freq[word[i]-'a']++;
        }

        if(countLetters <= 8){
            return word.size();
        }
        vector<pair<char,int>> freqPair;
        char ch = 'a';
        for(int i = 0; i<freq.size(); i++){
            freqPair.push_back({ch, freq[i]});
            ch++;
        }

        sort(freqPair.begin(), freqPair.end(), comp);
        for(int i = 0; i<freqPair.size(); i++){
            if(i < 8){
                ans += freqPair[i].second;
            }
            else if(i >= 8 && i <= 15){
                ans += 2*freqPair[i].second;
            }
            else if(i >= 16 && i <= 23){
                ans += 3*freqPair[i].second;
            }
            else{
                ans += 4*freqPair[i].second;
            }
        }
        return ans;
    }
};