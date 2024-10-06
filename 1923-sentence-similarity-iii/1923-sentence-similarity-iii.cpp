class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1 == sentence2) 
            return true;

        stringstream ss1(sentence1);
        stringstream ss2(sentence2);
        string word;

        vector<string> s1, s2;
        while(ss1>>word) s1.push_back(word);
        ss1.clear();
        while(ss2>>word) s2.push_back(word);
        ss2.clear();

        int n1 = s1.size(), n2 = s2.size();
        if(n1 > n2) {
            swap(n1, n2);
            swap(s1, s2);
        }

        int l = 0, r1 = n1 - 1, r2 = n2 - 1; 

        while(l < n1 && s1[l] == s2[l]){
            l++;
        }

        while(r1 >= 0 && s1[r1] == s2[r2]){
            r2--;
            r1--;
        }

        return r1 < l;

    }
};