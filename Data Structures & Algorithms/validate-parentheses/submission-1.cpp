class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mapping;
        mapping[')']='(';
        mapping[']']='[';
        mapping['}']='{';
        stack<char> st;
        for(auto it:s){
            if(it == '(' || it == '[' || it == '{'){
                st.push(it);
                continue;
            }
            else if(st.empty() || st.top() != mapping[it])return false;
            st.pop();
        }
        return st.empty();
    }
};
