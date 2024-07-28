class Solution {
public:
    
    vector<int> sieve(int n){
        vector<int> primes(n+1, 1);
        primes[0] = primes[1] = 0;
        
        for(int i = 2; i*i <= n; i++){
            
            if(primes[i] == 1){
                for(int j = i*i; j <= n; j+=i){
                    primes[j] = 0;
                }
            }
        }
        
        //adding prefixSum values
        for(int i = 1; i<=n; i++){
            primes[i] += primes[i-1];
        }
        return primes;
    }
    int nonSpecialCount(int l, int r) {
        int sqrtl = sqrt(l);
        int sqrtr = sqrt(r);
        
        if(sqrtl * sqrtl != l)
            sqrtl += 1;
        
        vector<int> primes = sieve(sqrtr);
        int countOfPrimes = primes[sqrtr] - primes[sqrtl-1];
        int ans = (r - l + 1) - countOfPrimes;
        return ans;
    }
};