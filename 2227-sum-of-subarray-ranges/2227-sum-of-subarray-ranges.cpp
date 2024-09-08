class Solution {
public:
    long long subArrayMaxs(vector<int> nums){
        stack<pair<int,int>> stForLeftMaxs;
        stack<pair<int,int>> stForRightMaxs;
        int n = nums.size();
        vector<int> leftCount(n, 0);
        vector<int> rightCount(n, 0);

        //counting next greater from left
        for(int i=0; i<n; i++){
            int count = 1;
            while(!stForLeftMaxs.empty() && stForLeftMaxs.top().first <= nums[i]){
                count += stForLeftMaxs.top().second;
                stForLeftMaxs.pop();
            }
            leftCount[i] = count;
            stForLeftMaxs.push({nums[i], count});
        }

        //counting next greater from right
        for(int i = n-1; i>=0; i--){
            int count = 1;
            //no <= to avoid duplicates
            while(!stForRightMaxs.empty() && stForRightMaxs.top().first < nums[i]){
                count += stForRightMaxs.top().second;
                stForRightMaxs.pop();
            }
            rightCount[i] = count;
            stForRightMaxs.push({nums[i], count});
        }

        long long sumOfMaxs = 0;
        for(int i=0; i<n; i++){
            sumOfMaxs += nums[i]*(long long)(leftCount[i] * rightCount[i]);
        }
        return sumOfMaxs;
    }

    long long subArrayMins(vector<int> nums){
        stack<pair<int,int>> stForLeftMins;
        stack<pair<int,int>> stForRightMins;
        int n = nums.size();
        vector<int> leftCount(n, 0);
        vector<int> rightCount(n, 0);

        //counting next smaller from left
        for(int i=0; i<n; i++){
            int count = 1;
            while(!stForLeftMins.empty() && stForLeftMins.top().first >= nums[i]){
                count += stForLeftMins.top().second;
                stForLeftMins.pop();
            }
            leftCount[i] = count;
            stForLeftMins.push({nums[i], count});
        }

        //counting next smaller from right
        for(int i = n-1; i>=0; i--){
            int count = 1;
            while(!stForRightMins.empty() && stForRightMins.top().first > nums[i]){
                count += stForRightMins.top().second;
                stForRightMins.pop();
            }
            rightCount[i] = count;
            stForRightMins.push({nums[i], count});
        }

        long long sumOfMins = 0;
        for(int i=0; i<n; i++){
            sumOfMins += nums[i]*(long long)(leftCount[i] * rightCount[i]);
        }
        return sumOfMins;
    }

    long long subArrayRanges(vector<int>& nums) {
        //sum of subarray ranges = sum of all subarray maxs - sum of all subarray mins
        //two functions - one to count sum of maxs and other to count sum of mins
        return subArrayMaxs(nums) - subArrayMins(nums);
    }
};