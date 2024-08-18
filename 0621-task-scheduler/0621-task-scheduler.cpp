class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        for(auto t : tasks){
            freq[t - 'A']++;
        }

        priority_queue<int> pq;
        for(int it : freq){
            if(it > 0)
                pq.push(it);
        }

        int time = 0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i = 1; i <= n+1; i++){
                if(!pq.empty()){
                    int f = pq.top();
                    pq.pop();
                    f--;
                    temp.push_back(f);
                }
            }
            
            for(int f : temp){
                if(f > 0)
                    pq.push(f);
            }

            if(pq.empty()){
                time += temp.size();
            }
            else{
                time += n + 1;
            }
        }
        return time;
    }
};