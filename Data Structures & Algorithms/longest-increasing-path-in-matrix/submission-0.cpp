class Solution {
public:
    int dfs(auto& matrix,int m,int n,int x,int y,auto& dp){
        if(dp[x][y] != -1)return dp[x][y];
        int dirX[] = {1,-1,0,0};
        int dirY[] = {0,0,-1,1};
        int ans = 1;
        for(int i=0;i<4;i++){
            int newX= x+dirX[i];
            int newY= y+dirY[i];
            if(newX < 0 || newY < 0 || newX >= m || newY >= n || matrix[newX][newY] <= matrix[x][y])continue;
            ans = max(ans, 1+ dfs(matrix,m,n,newX,newY,dp));
        }
        return dp[x][y] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dfs(matrix,m,n,i,j,dp));
            }
        }
        return ans;
    }
};
