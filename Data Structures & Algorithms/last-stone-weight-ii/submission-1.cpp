class Solution {
public:
    int solve(auto& stones,int sum ,int target,int index,int total,auto& dp){
        if(index == stones.size()){
            // if(sum == target)return 0;
            int b = total - sum;
            return abs(sum - b);
        }
        if(dp[index][sum ] != -1)return dp[index][sum];
        int notTake = solve(stones,sum,target,index+1,total,dp);
        int take = 1e9;
        if(index < stones.size())
            take = solve(stones,sum+stones[index],target,index+1,total,dp);
        return dp[index][sum] = min(take,notTake);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(),stones.end(),0);
        vector<vector<int>> dp(stones.size(),vector<int>(sum,-1));
        return solve(stones,0,((sum+1)/2),0,sum,dp);
    }
};