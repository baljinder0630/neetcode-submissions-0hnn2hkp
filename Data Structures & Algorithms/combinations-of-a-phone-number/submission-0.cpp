class Solution {
public:
    void solve(auto& digits,auto& mapping,auto& ans,auto& temp, int index){
        if(index == digits.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0 ; i < mapping[digits[index]].size(); i++){
            temp.push_back(mapping[digits[index]][i]);
            solve(digits,mapping,ans,temp,index+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)return{};
        unordered_map<char,string> mapping = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        vector<string> ans;
        string temp;
        solve(digits,mapping,ans,temp,0);
        return ans;
    }
};
