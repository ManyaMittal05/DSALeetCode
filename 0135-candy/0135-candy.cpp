class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n), right(n);

        left[0] = 1;
        for(int i = 1; i<n; i++){
            if(ratings[i] > ratings[i-1])
                left[i] = left[i-1] + 1;
            else
                left[i] = 1;
        }

        right[n-1] = 1;
        int sum = 0;
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1])
                right[i] = right[i+1] + 1;
            else
                right[i] = 1;
            sum += max(left[i], right[i]);
        }
        sum += max(left[n-1], right[n-1]);
        return sum;
    }
};