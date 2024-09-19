class Solution {
public:
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8));

        string yr, mon, d;

        while(year != 0){
            yr += to_string(year & 1);
            year = year >> 1;
        }

        while(month != 0){
            mon += to_string(month & 1);
            month = month >> 1;
        }

        while(day != 0){
            d += to_string(day & 1);
            day = day >> 1;
        }

        reverse(yr.begin(), yr.end());
        reverse(mon.begin(), mon.end());
        reverse(d.begin(), d.end());

        string ans = yr + "-" + mon + "-" + d;
        return ans;
    }
};