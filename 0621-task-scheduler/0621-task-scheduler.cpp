class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        //find frequency of each task in the queue
        for(auto t : tasks){
            freq[t - 'A']++;
        }

        priority_queue<int> pq;
        //insert the frequencies in  a max heap so they can be accessed in decreasing order
        for(int it : freq){
            if(it > 0)
                pq.push(it);
        }

        int time = 0;
        while(!pq.empty()){
            vector<int> temp;
            //for every task, n units of time is required for cool down
            //so when a task is performed it will again be performed after n+1 time units
            for(int i = 1; i <= n+1; i++){
                if(!pq.empty()){
                    //pick out the most frequent task & decrement its frequency
                    int f = pq.top();
                    pq.pop();
                    f--;
                    //push that frequency into the array so we can again insert it into the heap
                    temp.push_back(f);
                }
            }
            
            for(int f : temp){
                if(f > 0) //if freq of a task is not = 0, insert it back into the heap
                    pq.push(f);
            }

            if(pq.empty()){//if the queue becomes empty, means no time will be idle so just add the number of tasks performed
                time += temp.size();
            }
            else{ //every time n+1 time is comsumed 
                time += n + 1;
            }
        }
        return time;
    }
};