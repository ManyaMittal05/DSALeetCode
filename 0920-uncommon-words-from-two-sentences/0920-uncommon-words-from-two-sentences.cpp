class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        string word = "";
        for(int i = 0; i<s1.length(); i++){
            if(s1[i] == ' '){
                mp[word]++;
                word = "";
            }
            else{
                word += s1[i];
            }
        }

        mp[word]++;

        word = "";
        vector<string> ans;
        for(int i = 0; i<s2.length(); i++){
            if(s2[i] == ' '){
                mp[word]++;
                word = "";
            }else{
                word += s2[i];
            }
        }

        mp[word]++;

        for(auto it : mp){
            if(it.second == 1) ans.push_back(it.first);
        }

        return ans;
    }
};