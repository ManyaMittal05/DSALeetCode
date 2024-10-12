class Solution {
public:

    typedef pair<int, int> P;

    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        priority_queue<int, vector<int>, greater<int>> groupings;

        sort(intervals.begin(), intervals.end());

        for(auto interval : intervals){
            int start = interval[0];
            int end = interval[1];

            if(!groupings.empty() && start > groupings.top()){
                groupings.pop();
                groupings.push(end);
            }
            else{
                groupings.push(end);
            }
        } 
        return groupings.size();
    }
};