class MyCalendar {
    set<pair<int, int>> intervals;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        //find the first event that starts after or at the same time of the given event  
        auto it = intervals.lower_bound({start, end});

        //check if the current event overlaps with the next event
        if(it != intervals.end() && it->first < end)
            return false;

        //check if the given interval overlap with the previous interval
        if(it != intervals.begin()){
            auto prevIt = prev(it);
            if(prevIt->second > start)
                return false;
        }

        intervals.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */