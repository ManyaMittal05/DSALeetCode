class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;
        int mask = 0;
        mp[mask] = -1;
        int result = 0;

        for(int i = 0; i<s.size(); i++){
            if(s[i] == 'a'){
                mask ^= 1;
            }
            else if(s[i] == 'e'){
                mask ^= (1<<1);
            }
            else if(s[i] == 'i'){
                mask ^= (1 << 2);
            }
            else if(s[i] == 'o'){
                mask ^= (1 << 3);
            }
            else if(s[i] == 'u'){
                mask ^= (1 << 4);
            }

            if(mp.find(mask) != mp.end()){
                result = max(result, i - mp[mask]);
            }
            else{
                mp[mask] = i;
            }
        }
        return result;
    }
};