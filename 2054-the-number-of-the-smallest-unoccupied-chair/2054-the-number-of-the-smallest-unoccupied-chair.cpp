class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> chairs(n, -1);

        int targetFrdArrTime = times[targetFriend][0]; //arrival times are distinct

        sort(times.begin(), times.end());

        for(auto time : times){
            int arrTime = time[0];
            int deptTime = time[1];

            for(int i = 0; i < n; i++){
                if(chairs[i] <= arrTime){
                    chairs[i] = deptTime;

                    if(targetFrdArrTime == arrTime)
                        return i;
                    break;
                }
            }
        }
        return -1;
    }
};