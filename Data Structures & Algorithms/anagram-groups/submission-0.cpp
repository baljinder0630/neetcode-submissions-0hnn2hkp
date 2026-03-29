class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,int> m;
        vector<vector<string>> ans;
        for(int i= 0; i<strs.size(); i++){
            map<char,int> freq;
            for(auto it:strs[i]){
                freq[it]++;
            }
            if(m.count(freq)){
                ans[m[freq]].push_back(strs[i]);
            }
            else{
                ans.push_back({strs[i]});
                m[freq] = ans.size()-1;
            }
        }
        return ans;
    }
};
