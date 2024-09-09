class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& heights){
        int n = heights.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()) nse[i] = st.top()-1;
            else nse[i] = n-1;
            st.push(i);
        }
        return nse;
    }

    vector<int> prevSmallerEle(vector<int>& heights){
        int n = heights.size();
        vector<int> pse(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()) pse[i] = st.top()+1;
            else pse[i] = 0;
            st.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = nextSmallerEle(heights);
        vector<int> pse = prevSmallerEle(heights);
        int n = heights.size();
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int area = heights[i] * (nse[i] - pse[i] + 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};