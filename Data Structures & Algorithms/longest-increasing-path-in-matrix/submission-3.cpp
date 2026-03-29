class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> indegree(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0)indegree[i-1][j] += matrix[i][j] < matrix[i-1][j];
                if(j>0)indegree[i][j-1] += matrix[i][j] < matrix[i][j-1];
                if(i<m-1)indegree[i+1][j] += matrix[i][j] < matrix[i+1][j];
                if(j<n-1)indegree[i][j+1] += matrix[i][j] < matrix[i][j+1];
            }
        }
        queue<tuple<int,int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(indegree[i][j]==0)q.push({i,j,1});
            }
        }
        int dirX[] = {-1,1,0,0};
        int dirY[] = {0,0,1,-1};
        int ans=0;
        while(!q.empty()){
            auto [x,y,count] = q.front();
            q.pop();
            ans = max(ans, count);
            for(int i=0;i<4;i++){
                int newX = x + dirX[i];
                int newY = y + dirY[i];
                if(newX < 0 || newY< 0 || newX >= m || newY >= n || matrix[x][y] >= matrix[newX][newY])continue;
                indegree[newX][newY]--;
                if(indegree[newX][newY]==0){
                    q.push({newX,newY,count+1});
                }
            }
        }
        return ans;
    }
};
