class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;
        if(a > 0) maxHeap.push({a, 'a'});
        if(b > 0) maxHeap.push({b, 'b'});
        if(c > 0) maxHeap.push({c, 'c'});
        int succChar = 1;
        auto p = maxHeap.top();
        string ans = "";
        ans += p.second;
        p.first--;
        maxHeap.pop();
        if (p.first != 0)
            maxHeap.push(p);

        int flag = 1;
        while (!maxHeap.empty() && flag == 1) {
            flag = 0;
            if (succChar < 2) {
                if (maxHeap.top().second == ans.back()) {
                    succChar++;
                } else {
                    succChar = 1;
                }
                auto p = maxHeap.top();
                ans += p.second;
                p.first--;
                maxHeap.pop();
                if (p.first != 0)
                    maxHeap.push(p);
                flag = 1;
            } else if (succChar == 2) {
                if (maxHeap.top().second == ans.back()) {
                    auto p1 = maxHeap.top();
                    maxHeap.pop();
                    if (!maxHeap.empty()) {
                        auto p = maxHeap.top();
                        ans += p.second;
                        p.first--;
                        maxHeap.pop();
                        if (p.first != 0)
                            maxHeap.push(p);
                        maxHeap.push(p1);
                        succChar = 1;
                        flag = 1;
                    }
                } else {
                    auto p = maxHeap.top();
                    ans += p.second;
                    p.first--;
                    maxHeap.pop();
                    if (p.first != 0)
                        maxHeap.push(p);
                    flag = 1;
                }
            }
        }
        return ans;
    }
};