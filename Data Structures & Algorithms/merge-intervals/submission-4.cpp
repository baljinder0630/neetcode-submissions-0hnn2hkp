class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> interval;
        map<int,int> event;
        for(auto it:intervals){
            event[it[0]]++;
            event[it[1]]--;
        }
        int have = 0;
        for(auto it:event){
            if(interval.empty()){
                interval.push_back(it.first);
            }
            have += it.second;
            if(have == 0){
                interval.push_back(it.first);
                ans.push_back(interval);
                interval.clear();
            }
        }
        return ans;
    }
};
