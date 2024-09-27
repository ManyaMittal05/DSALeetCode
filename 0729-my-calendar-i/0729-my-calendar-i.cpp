class MyCalendar {
    vector<pair<int, int>> bookings;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it : bookings){
            //check if the booking is overlapping with an already existing event
            if(max(it.first, start) < min(it.second, end))
                return false;
        }
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */