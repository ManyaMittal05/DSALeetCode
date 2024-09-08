class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        //if the asteroid is -ve i.e moving left, it will not collide so keep adding it to the stack
        //if the asteroid is +ve i.e moving right, it will collide if prev asteroid was -ve
        //so while stack's top is -ve and its abs value is smaller than asteroids curr val, keep popping out the element fro stack
        //if stack's top is -ve and its abs value is equal to current asteroid value, pop out the stack's top
        //if current asteroid value is less than abs stack's top value then do nothing as this asteroid will explode
        //now if stack is empty or stack's top is +ve push asteroid in stack as asteroid value is also +ve so they will not collide
        for(int i=asteroids.size()-1; i>=0; i--){
            if(st.empty() || asteroids[i] < 0){
                st.push(asteroids[i]);
            }
            else{
                while(!st.empty() && st.top() < 0 && abs(st.top()) < asteroids[i])
                    st.pop();
                if(!st.empty() && st.top() < 0 && abs(st.top()) == asteroids[i]){
                    st.pop();
                }
                else{
                    if(st.empty() || st.top() > 0)
                        st.push(asteroids[i]);
                }
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};