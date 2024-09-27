class MyCalendarTwo {
    vector<pair<int,int>> doubleBookings;
    vector<pair<int,int>> overallBookings;
public:
    MyCalendarTwo() {
        
    }

    bool checkOverlapped(int s1, int e1, int s2, int e2){
        if(max(s1, s2) < min(e1, e2))
            return true;
        return false;
    }
    
    bool book(int start, int end) {

        //check if triple booking is being created
        for(auto it : doubleBookings){
            if(checkOverlapped(it.first, it.second, start, end))
                return false; //triple booking detected
        }

        //check if double booking is being created
        for(auto it : overallBookings){
            if(checkOverlapped(it.first, it.second, start, end)){
                //if overlapping then puch overlapping reegion in the double booking vector
                int newstart = max(it.first, start);
                int newend = min(it.second, end);
                doubleBookings.push_back({newstart, newend});
            }
        }
        //push the event interval in overallBookings
        overallBookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */