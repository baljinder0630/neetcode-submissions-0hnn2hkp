class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty())return {newInterval};
        vector<vector<int>> ans;
        int left = 0, right = intervals.size()-1;
        while(left <= right){
            int mid = (left + right )/ 2;
            if(intervals[mid][0] < newInterval[0]){
                left = mid+1;
            }
            else right = mid-1;
        }
        intervals.insert(intervals.begin()+left,newInterval);
        for(int i=0;i<intervals.size(); i++){
            if(ans.empty() || (ans.back()[1] < intervals[i][0])){
                ans.push_back(intervals[i]);
            }
            else{
                ans[ans.size()-1][1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};
