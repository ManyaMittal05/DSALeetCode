class Solution {
public:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    bool doesAliceWin(string s) {
        int count = 0;
        int lastVowInd = 0;
        for(int i = 0; i< s.length(); i++){
            if(isVowel(s[i])){
                count ++;
            }
        }  
        
        if(count == 0) return false;
        return true;
        
    }
};