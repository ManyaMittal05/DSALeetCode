class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits, sortedDigs;
        while(num != 0){
            int dig = num % 10;
            digits.push_back(dig);
            sortedDigs.push_back(dig);
            num = num / 10;
        }

        int n = digits.size();
        reverse(digits.begin(), digits.end());
        sort(sortedDigs.rbegin(), sortedDigs.rend());

        int firstDifferentDig = -1;
        int index = -1;
        for(int i = 0; i < n; i++){
            if(sortedDigs[i] != digits[i]){
                firstDifferentDig = sortedDigs[i];
                index = i;
                break;
            }
        }

        if(firstDifferentDig != -1) {
            for(int i = n -1; i >= 0; i--){
                if(digits[i] == firstDifferentDig){
                    swap(digits[i], digits[index]);
                    break;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = ans * 10 + digits[i];
        }
        return ans;
    }
};