class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> freq(201, 0);
        for(auto n : nums){
            freq[n + 100]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b){
            if(freq[100 + a] < freq[100 + b]) return true;
            else if(freq[100 + a] > freq[100 + b]) return false;
            else{
                if(a > b) return true;
                return false;
            }
        });

        return nums;
    }
};