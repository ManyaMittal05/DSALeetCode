class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> mappedVal(n);
        for(int i = 0; i<n; i++){
            int number = nums[i];
            int newNum = 0;
            int p = 1;
            if(number == 0) newNum = mapping[0];
            while(number > 0){
                int digit = number%10;
                newNum = mapping[digit] * p + newNum;
                number = number / 10;
                p *= 10;
            }
            mappedVal[i] = {nums[i], newNum};
        }

        vector<int> ans;
        stable_sort(mappedVal.begin(), mappedVal.end(), [&](auto a, auto b){
            return a.second < b.second;
        });
        for(int i = 0; i< n; i++){
            ans.push_back(mappedVal[i].first);
        }
        return ans;
    }
};