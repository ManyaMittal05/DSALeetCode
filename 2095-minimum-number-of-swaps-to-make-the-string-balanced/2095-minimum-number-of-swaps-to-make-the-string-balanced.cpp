class Solution {
public:
    int minSwaps(string s) {
        int count = 0;
        int open = 0, close = 0;
        int n = s.length();
        int end = n - 1;

        for(int i = 0; i < n; i++){
            if(s[i] == '[') open++;
            else close++;

            if(close > open){
                while(end >= 0 && s[end] != '[') end--;
                count++;
                swap(s[i], s[end]);
                close--;
                open++;
            }
        }

        return count;
    }
};

auto speedup = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();