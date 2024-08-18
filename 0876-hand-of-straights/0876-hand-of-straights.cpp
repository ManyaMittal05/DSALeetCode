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

        //stroe freq of each number in a map
        unordered_map<int, int> mp;
        for(auto i : hand){
            mp[i]++;
        }

        //maintain a min heap which will store pair of number and its frequency
        //we will orderwise make a group of numbers 
        //when a number is used it freq will also be decreased
        priority_queue<pair<int,int>, vector<pair<int, int>>, compare> pq; //minHeap

        //inset the number along with its freq in a min heap
        //elements will be stored in min heap acc to their values & not their freq
        for(auto [num, count] : mp){
            pq.push({num, count});
        }

        //traverse while the queue is not empty
        while(!pq.empty()){
            //this will store the used numbers in the group along with their decremented freq
            vector<pair<int, int>> temp;

            //to make a group of given size
            for(int i = 1; i<=groupSize; i++){
                pair<int,int> p = pq.top();
                pq.pop();
                //if the prev element and curr element are not consecutive, 
                //it means that a group cannot be formed of the given size
                //with consecutive numbers
                //so return false
                if(!temp.empty() && temp.back().first + 1 != p.first){
                    return false;
                }
                //if the elements are consecutive, they can be used
                //so push them into the temp array with decremented frequency
                else{
                    p.second--;
                    temp.push_back(p);
                }
            }

            for(auto p : temp){
                //if t=freq of any used element is still left and not 0
                //then push that element back into the min heap
                if(p.second > 0){
                    pq.push(p);
                }
            }
        }

        return true;
    }
};