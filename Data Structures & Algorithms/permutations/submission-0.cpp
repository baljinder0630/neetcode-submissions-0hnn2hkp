class Solution {
public:
    void solve(auto& nums,auto& ans,auto& visited,auto& temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i =0; i < nums.size(); i++){
            if(visited[i])continue;
            visited[i]=1;
            temp.push_back(nums[i]);
            solve(nums,ans,visited,temp);
            temp.pop_back();
            visited[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> visited(nums.size(),0);
        vector<int> temp;
        solve(nums,ans,visited,temp);
        return ans;
    }
};
