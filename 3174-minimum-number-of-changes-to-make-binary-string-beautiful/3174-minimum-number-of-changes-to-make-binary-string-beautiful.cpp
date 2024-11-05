class Solution {
public:
    int minChanges(string s) {
        char ch = s[0];
        int n = s.size();
        int count = 1;
        int changes = 0;

        for(int i = 1; i < n; i++){
            if(s[i] != s[i-1]){
                if(count % 2 != 0){
                    changes += 1;
                    count = 0;
                }
                else{
                    count = 1;
                }
            }
            else{
                count++;
            }
        }
        return changes;
    }
};