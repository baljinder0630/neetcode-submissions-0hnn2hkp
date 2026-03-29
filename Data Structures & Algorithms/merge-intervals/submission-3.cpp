class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(auto it:intervals){
            if(ans.empty()){
                ans.push_back(it);
            }
            else if(ans.back()[1] >= it[0]){
                ans.back()[1] = max(ans.back()[1],it[1]);
            }
            else{
                ans.push_back(it);
            }
        }
        return ans;
    }
};
