class Solution {
public:
    string compressedString(string word) {
        char ch = word[0];
        int count = 1;
        string comp = "";
        for(int i = 1; i < word.length(); i++){
            if(word[i] == ch){
                count++;
                if(count > 9){
                    string s = "9";
                    s += ch;
                    comp += s;
                    count = 1;
                }
            }
            else{
                comp += to_string(count) + ch;
                count = 1;
                ch = word[i];
            }
        }
        comp += to_string(count) + ch;
        return comp;
    }
};