class Solution {
public:
    int solve(int i,int j,auto& arr,int& m,int& n,auto& dp){
        if(i < 0 || j < 0 || i >= m || j >= n || arr[i][j] == 1)return 0;
        if(i == m-1 && j == n-1)return 1;
        if(dp[i][j] != -1)return dp[i][j];
        arr[i][j]=1;
        int dirX[] = {1,0};
        int dirY[] = {0,1};
        int ans=0;
        for(int index=0;index < 2; index++){
            int newX = i + dirX[index];
            int newY = j + dirY[index];
            ans += solve(newX,newY,arr,m,n,dp);
        }
        arr[i][j]=0;
        return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size(), n=arr[0].size();

        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,arr,m,n,dp);
    }
};