class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        
        if(set.find(endWord) == set.end())
            return 0;

        set.erase(beginWord);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        int ans = 0;

        while(!q.empty()){
            auto p = q.front();
            string word = p.first;
            int count = p.second;
            q.pop();

            for(int i = 0; i < word.length(); i++){
                string w = word;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    w[i] = ch;
                    if(set.find(w) != set.end()){
                        q.push({w, count + 1});
                        ans = max(ans, count + 1);
                        set.erase(w);
                    }
                }
            }
        }
        return ans;
    }
};