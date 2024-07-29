class Solution {
public:
    //we will fix j at a index 
    //for ascending order teams:- 
        //count num of ele less than rating[j] at left of j
        //count num of ele greater than rating[j] at right of j
        //total ascending teams = countSmallerLeft * countLargerRight
    //for descending order teams:- 
        //count num of ele greater than rating[j] at left of j
        //count num of ele less than rating[j] at right of j
        //total ascending teams = countLargerLeft * countSamllerRight
    
    int numTeams(vector<int>& rating) {
        int teams = 0;
        int n = rating.size();
        for(int j = 1; j<n-1; j++){
            int countSmallerLeft = 0, countLargerRight = 0, countLargerLeft = 0, countSmallerRight = 0;
            for(int i = 0; i<j; i++){
                if(rating[i] < rating[j])
                    countSmallerLeft++;
                if(rating[i] > rating[j])
                    countLargerLeft++;
            }

            for(int k = j+1; k<n; k++){
                if(rating[k] > rating[j])
                    countLargerRight++;
                if(rating[k] < rating[j])
                    countSmallerRight++;
            }

            teams += countSmallerLeft * countLargerRight; //for ascending
            teams += countLargerLeft * countSmallerRight; //for descending
        }
        return teams;
    }
};