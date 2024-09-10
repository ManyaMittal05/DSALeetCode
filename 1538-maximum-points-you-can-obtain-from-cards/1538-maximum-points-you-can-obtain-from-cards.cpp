class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0;
        int n = cardPoints.size();
        for(int i = 0; i<k; i++){
            leftSum += cardPoints[i];
        }

        int maxScore = leftSum;
        int rindex = n-1;
        int rightSum = 0;

        for(int i = k-1; i >= 0; i--){
            leftSum -= cardPoints[i];
            rightSum += cardPoints[rindex--];
            maxScore = max(maxScore, leftSum + rightSum);
        }

        return maxScore;
    }
};