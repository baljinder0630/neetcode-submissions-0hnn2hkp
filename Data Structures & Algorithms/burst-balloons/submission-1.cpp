class Solution {
public:
    int solve(vector<int>& nums,int left,int right,auto& dp){
        if(left > right)return 0;
        if(dp[left][right] != -1)return dp[left][right];
        int ans = 0;
        for(int i=left; i <= right; i++){
            ans = max(ans, nums[i]*nums[left-1]*nums[right+1] + solve(nums,left,i-1, dp) + solve(nums,i+1,right, dp));
        }
        return dp[left][right] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return solve(nums,1,n, dp);
    }
};
