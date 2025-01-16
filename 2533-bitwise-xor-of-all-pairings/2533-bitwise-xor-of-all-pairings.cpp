class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 % 2 == 0 && n2 % 2 == 0) return 0;

        int xor1 = 0, xor2 = 0;
        for(auto i : nums1)
            xor1 ^= i;
        
        for(auto j : nums2)
            xor2 ^= j;

        if(n1 % 2 == 0) return xor1;
        else if(n2 % 2 == 0) return xor2;
        
        return xor1 ^ xor2;
    }
};