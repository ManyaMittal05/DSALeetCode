class Solution {
public:
    double myPow(double x, int n) {
        int power = abs(n);
        double ans = 1.0;
        while(power > 0){
            if(power % 2 == 0){
                x = x * x;
                power = power / 2;
            }
            else{
                ans = ans * x;
                power -= 1;
            }
        }

        if(n < 0 ) return 1.0/ans;
        return ans;
    }
};