class Solution {
public:
    int solve(vector<int>& nums,int target,int index, auto& dp,int& total){
        if(index == nums.size()){
            return target == 0;
        }
        if(dp[(target + total) % total][index] != -1)return dp[(target + total) % total][index];
        int add = solve(nums, target - nums[index], index+1, dp, total);
        int subt = solve(nums, target + nums[index], index+1, dp, total);
        return dp[(target + total) % total][index] = add + subt;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = (2 * accumulate(nums.begin(), nums.end(), 0)) + 1 + target;

        vector<vector<int>> dp(total , vector<int>(nums.size(), -1));
        return solve(nums, target, 0, dp, total);
    }
};
