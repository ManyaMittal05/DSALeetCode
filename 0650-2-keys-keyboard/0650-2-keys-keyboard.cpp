class Solution {
    //recursive solution
public:
    int solve(int n, int currA, int clipA) {
        if (currA == n) {
            return 0;
        }

        if(currA > n){
            return 1e7;
        }

        // Copy and paste operation
        int copyPaste = 1 + 1 + solve(n, currA + currA, currA);

        //no copy, only paste
        int paste = 1 + solve(n, currA + clipA, clipA);

        return min(copyPaste, paste);
    }

    int minSteps(int n) {
        if(n == 1 ) return 0;

        int currA = 1, clipA = 1;
        return 1 + solve(n, currA, clipA);
    }
};