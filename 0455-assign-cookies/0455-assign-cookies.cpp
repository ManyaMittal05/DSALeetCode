class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i = 0, j = 0;
        while(i < s.size() && j < g.size()){
            if(g[j] <= s[i]){
                count++;
                j++;
            }
            i++;
        }
        return count;
    }
};