#define MOD 1000000007
class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& arr){
        int n = arr.size();
        vector<int> nextSmaller(n);
        stack<pair<int,int>> st;

        for(int i = n-1; i >= 0; i--){
            int count = 1;
            while(!st.empty() && st.top().first >= arr[i]){
                count += st.top().second;
                st.pop();
            }
            nextSmaller[i] = count;
            st.push({arr[i], count});
        }

        return nextSmaller;
    }

    vector<int> prevSmallerEle(vector<int>& arr){
        stack<pair<int,int>> st;
        int n = arr.size();
        vector<int> prevSmaller(n);

        for(int i = 0; i<n; i++){
            int count = 1;
            while(!st.empty() && st.top().first > arr[i]){
                count += st.top().second;
                st.pop();
            }

            prevSmaller[i] = count;
            st.push({arr[i], count});
        }
        return prevSmaller;
    }


    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nextSmaller = nextSmallerEle(arr);
        vector<int> prevSmaller = prevSmallerEle(arr);

        long long sum = 0;
        for(int i = 0; i<arr.size(); i++){
            long long contri = arr[i] * (long long) (nextSmaller[i] * prevSmaller[i]);
            sum += contri;
        }    

        return sum % MOD;
    }
};