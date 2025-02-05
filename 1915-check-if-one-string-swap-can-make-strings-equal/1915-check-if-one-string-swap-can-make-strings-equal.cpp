class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0; 
        unordered_map<char, int> mp;
        for(char ch : s1){
            mp[ch]++;
        }

        for(char ch : s2){
            mp[ch]--;
            if(mp[ch] < 0)
                return false;
        }

        for(int i  = 0; i < s1.size(); i++){
            if(s1[i] != s2[i])
                count++;
        }
        return (count <= 2);
    }
};