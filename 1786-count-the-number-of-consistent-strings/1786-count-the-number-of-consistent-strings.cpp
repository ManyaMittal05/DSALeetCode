class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> set;

        for(char ch : allowed){
            set.insert(ch);
        }

        int count = 0;
        
        for(string w : words){
            int flag = 1;
            for(char ch : w){
                if(set.find(ch) == set.end()){
                    flag = 0;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};