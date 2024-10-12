class Solution {
public:
    typedef pair<int, int> P;

    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        priority_queue<P, vector<P>, greater<P>> occupied; //departure time, chair
        priority_queue<int, vector<int>, greater<int>> freeChair;
        int targetArr = times[targetFriend][0];

        sort(times.begin(), times.end());

        int chair = 0;
        if(targetArr == times[0][0]) return 0;

        for(auto time : times){
            int arrTime = time[0];
            int deptTime = time[1];

            while(!occupied.empty() && occupied.top().first <= arrTime){
                freeChair.push(occupied.top().second);
                occupied.pop();
            }

            if(freeChair.empty()){
                occupied.push({deptTime, chair});

                if(arrTime == targetArr)
                    return chair;
                chair++;
            }
            else{
                int leastAvailChair = freeChair.top();
                if(arrTime == targetArr)
                    return leastAvailChair;
                occupied.push({deptTime, leastAvailChair});
                freeChair.pop();
            }
        }
        return -1;
    }
};