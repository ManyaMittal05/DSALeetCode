class compare{
    public:
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
        return a.first > b.first;
    }
};

class Solution {
public:

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;

        auto hash_pair = [](const pair<int, int>& p){
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        };

        unordered_set<pair<int,int>, decltype (hash_pair)> set(0, hash_pair);

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
            compare> pq;

        //first ele of both arrays will surely give a min sum as 
        //they are the msallest elements coz the arrays are sorted
        pq.push({nums1[0] + nums2[0], {0, 0}}); 

        while(k > 0 && !pq.empty()){
            //pop out the top of the heap
            //i.e. the min sum values and the indices from each array that give min sum
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            pair<int, int> indices = p.second;
            int i = indices.first;
            int j = indices.second;

            //push the values at the indices in the result array
            result.push_back({nums1[i], nums2[j]});
            k--; //decrement the count of k as we need to find only k pairs

            //for next possible pair i.e. (i+1, j) check if they are not out of bound
            if(i + 1 < nums1.size()){
                //check if the new pair already exits in the min Heap
                //if not then insert it into the set and the min heap
                //along with the result so it can maintain min heap property
                if(set.find({i+1, j}) == set.end()){
                    set.insert({i+1, j});
                    pq.push({nums1[i+1] + nums2[j], {i+1, j}});
                }
            }

            //for next possible pair i.e. (i, j+1) check if they are not out of bound
            if(j + 1 < nums2.size()){
                //check if the new pair already exits in the min Heap
                //if not then insert it into the set and the min heap
                //along with the result so it can maintain min heap property
                if(set.find({i, j+1}) == set.end()){
                    set.insert({i, j+1});
                    pq.push({nums1[i] + nums2[j+1], {i, j+1}});
                }
            }
        }

        return result;
    }
};