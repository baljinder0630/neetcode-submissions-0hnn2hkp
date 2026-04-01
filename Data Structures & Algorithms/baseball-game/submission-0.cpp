class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto it:operations){
            if(it == "+" || it == "D" || it == "C"){
                if(st.empty())continue;
                if(it == "+"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.push(a);
                    st.push(a+b);
                }
                else if(it == "D"){
                    st.push(st.top() * 2);
                }
                else{
                    st.pop();
                }
            }
            else{
                int num = stoi(it);
                st.push(num);
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};