class compare{
    public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first > b.first;
    }
};

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0 ) return false;

        unordered_map<int, int> mp;
        for(auto i : hand){
            mp[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int, int>>, compare> pq; //minHeap

        for(auto [num, count] : mp){
            pq.push({num, count});
        }

        while(!pq.empty()){
            vector<pair<int, int>> temp;
            for(int i = 1; i<=groupSize; i++){
                pair<int,int> p = pq.top();
                pq.pop();
                if(!temp.empty() && temp.back().first + 1 != p.first){
                    return false;
                }
                else{
                    p.second--;
                    temp.push_back(p);
                }
            }

            for(auto p : temp){
                if(p.second > 0){
                    pq.push(p);
                }
            }
        }

        return true;
    }
};