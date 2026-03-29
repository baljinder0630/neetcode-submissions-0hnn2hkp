class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto it:strs){
            ans += it;
            
            ans.push_back((char)129);
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        stringstream ss(s);
        string str;
        while(getline(ss,str,(char)129)){
            ans.push_back(str);
        }
        return ans;
    }
};
