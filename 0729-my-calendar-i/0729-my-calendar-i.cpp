class MyCalendar {
    vector<pair<int, int>> intervals;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(intervals.size() == 0){
            intervals.push_back({start, end});
            return true;
        }
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(end <= intervals[mid].first){
                if(mid - 1 < 0){
                    intervals.push_back({start, end});
                    return true;
                }
                else if(intervals[mid-1].second <= start){
                    intervals.push_back({start, end});
                    return true;
                }
                else{
                    high = mid - 1;
                }
            }
            else if(start >= intervals[mid].second){
                if(mid + 1 >= n){
                    intervals.push_back({start, end});
                    return true;
                }
                else if(intervals[mid+1].first >= end){
                    intervals.push_back({start, end});
                    return true;
                }
                else{
                    low = mid + 1;
                }
            }
            else return false;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */