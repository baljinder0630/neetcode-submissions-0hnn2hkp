class Solution {
public:
    void solve(auto& nums,auto& ans,int& mask,auto& temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i =0; i < nums.size(); i++){
            if(mask & (1 << i))continue;
            mask = mask | (1 << i);
            temp.push_back(nums[i]);
            solve(nums,ans,mask,temp);
            temp.pop_back();
            mask = mask ^ ( 1 << i);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int mask = 0;
        vector<int> temp;
        solve(nums,ans,mask,temp);
        return ans;
    }
};
