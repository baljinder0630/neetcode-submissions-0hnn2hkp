class Solution {
public:
    bool isPalindrome(string& s,int i,int j){
        while(i < j){
            if(s[i] != s[j])return false;
            i++;j--;
        }
        return true;
    }
    void solve(string& s,auto& ans,auto& temp,int index){
        if(index >= s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                solve(s,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,ans,temp,0);
        return ans;
    }
};
