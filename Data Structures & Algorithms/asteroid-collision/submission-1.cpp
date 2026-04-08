class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto it:asteroids){
            while(!st.empty() && it < 0 && st.top() > 0){
                int diff = st.top() + it;
                if(diff < 0){
                    st.pop();
                }else if(diff > 0){
                    it = 0;
                }
                else{
                    it = 0;
                    st.pop();
                }
            }
            if(it != 0)st.push(it);
            
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};