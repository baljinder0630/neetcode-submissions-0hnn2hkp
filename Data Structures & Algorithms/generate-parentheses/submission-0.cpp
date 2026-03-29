class Solution {
public:
    void solve(int i,int j,auto& ans,string& temp){
        if(i == 0 && j == 0){
            ans.push_back(temp);
            return;
        }
        if(i >= 0){
            temp.push_back('(');
            solve(i-1,j,ans,temp);
            temp.pop_back();
        }
        if(j >= 0 && i < j){
            temp.push_back(')');
            solve(i,j-1,ans,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        solve(n,n,ans,temp);
        return ans;
    }
};
