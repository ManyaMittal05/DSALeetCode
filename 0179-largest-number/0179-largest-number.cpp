class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string> strNums(nums.size());
        for(int i = 0; i<nums.size(); i++){
            strNums[i] = to_string(nums[i]);
        }
        
        sort(strNums.begin(), strNums.end(), [](string a, string b){
            return (a + b > b + a);
        });

        if(strNums[0] == "0") return "0";

        string ans = "";
        for(int i = 0; i<strNums.size(); i++){
            ans += strNums[i];
        }

        return ans;
    }
};