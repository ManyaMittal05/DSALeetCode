class Solution {
public:
    long long countZeros(vector<int>& nums){
        long long count = 0;
        for(auto n : nums){
            if(n == 0)
                count++;
        }
        return count;
    }

    long long sumOfNums(vector<int>& nums){
        long long sum = 0;
        for(auto n : nums){
            sum += n;
        }
        return sum;
    }

    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = sumOfNums(nums1);
        long long sum2 = sumOfNums(nums2);
        long long zeroCount1 = countZeros(nums1);
        long long zeroCount2 = countZeros(nums2);

        sum1 += zeroCount1;
        sum2 += zeroCount2;

        if(sum1 > sum2){
            long long req = sum1 - sum2;
            if(zeroCount2 == 0) return -1;
            else
                return sum1;
        }
        else if(sum2 > sum1){
            long long req = sum2 - sum1;
            if(zeroCount1 == 0) return -1;
            else
                return sum2;
        }

        return sum2;
    }
};