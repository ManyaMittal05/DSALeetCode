class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        for(auto time : timePoints){
            string hrs = time.substr(0, 2);
            string mins = time.substr(3, 2);

            int total_mins = stoi(hrs)*60 + stoi(mins);
            // if(stoi(hrs) == 0){
            //     minutes.push_back(24*60 + stoi(mins));
            // }
                minutes.push_back(24*60 + total_mins);
            minutes.push_back(total_mins);
        }

        sort(minutes.begin(), minutes.end());

        int minDiff = minutes[1] - minutes[0];
        for(int i = 2; i<minutes.size(); i++){
            minDiff = min(minDiff, minutes[i] - minutes[i-1]);
        }
        return minDiff;
    }
};