class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i < tokens.size(); i++){
            string val = tokens[i];
            if(val == "+" || val == "-" || val == "/" || val == "*"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(val == "+")
                    st.push(a+b);
                else if(val == "-")
                    st.push(b-a);
                else if(val == "*")
                    st.push(a*b);
                else
                    st.push(b/a);
            }
            else 
                st.push(stoi(val));
        }
        return st.empty() ? -1: st.top();
    }
};
