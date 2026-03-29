class Solution {
public:
    void solve(auto& arr,int target,int index,auto& ans,auto& temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int k = index;k < arr.size(); k++){
            if(k > index && arr[k] == arr[k-1])continue;
            if(arr[k] > target)break;
            temp.push_back(arr[k]);
            solve(arr,target-arr[k],k,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,0,ans,temp);
        return ans;
    }
};