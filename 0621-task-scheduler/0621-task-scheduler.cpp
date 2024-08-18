class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(auto t : tasks){
            freq[t - 'A']++;
        }

        sort(freq.begin(), freq.end());
        //the task with max freq woulf hav been in the end now i.e. on 25th index

        int maxFreq = freq[25];
        int gaddhe = maxFreq - 1; //number of spaces between maxFreq character
        int idleSlots = n * gaddhe; // number of empty slots in those gaddhe

        for(int i = 24; i >= 0; i--){
            idleSlots -= min(freq[i], gaddhe);
        }

        if(idleSlots > 0){
            return tasks.size() + idleSlots;
        }

        return tasks.size();
    }
};