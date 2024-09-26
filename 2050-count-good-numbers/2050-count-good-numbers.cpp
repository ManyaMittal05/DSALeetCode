long long MOD = 1e9 + 7;
class Solution {
public:
    long long power(long long x, long long n){
        long long ans = 1;
        x = x % MOD;
        while(n > 0){
            if(n % 2 == 0){
                x = (x * x) % MOD;
                n = n / 2;
            }
            else{
                ans = (ans * x) % MOD;
                n = n - 1;
            }
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long powerCountOf4 = n / 2;
        long long powerCountOf5 = (n % 2 == 0) ? n/2 : (n/2 + 1);
        long long contribution4 = power(4, powerCountOf4);
        long long contribution5 = power(5, powerCountOf5);
        return (contribution4 * contribution5) % MOD;
    }
};