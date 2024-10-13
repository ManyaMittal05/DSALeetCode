class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();

        if(k <= x){
            for(int i = 0; i < n - k + 1; i++){
                int sum = 0;
                for(int j = i; j < i + k; j++){
                    sum += nums[j];
                }
                ans.push_back(sum);
            }
            return ans;
        }

        for(int i = 0; i < n - k + 1; i++){
            int sum = 0;
            set<pair<int, int>> st;
            vector<int> freq(51, 0);
            for(int j = i; j < i + k; j++){
                if(st.find({freq[nums[j]], nums[j]}) != st.end()){
                    st.erase({freq[nums[j]], nums[j]});
                }
                freq[nums[j]]++;
                st.insert({freq[nums[j]], nums[j]});
            }

            for(int m = 0; m < x; m++){
                if(!st.empty()){
                    auto it = *(st.rbegin());
                    // cout<<it.first<<it.second<<endl;
                    sum += (it.first * it.second);
                    st.erase(it);
                }
            }
            ans.push_back(sum);
        }

        return ans;
    }
};