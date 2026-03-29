class Solution {
public:
    void bfs(auto& board,int m,int n){
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(board[i][j] == 'O'){
                        q.push({i,j});
                        board[i][j]='Z';
                    }
                }
            }
        }
        int dirX[] = {1,-1,0,0};
        int dirY[] = {0,0,-1,1};
        while(!q.empty()){
            auto [x,y]= q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x + dirX[i];
                int ny = y + dirY[i];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || board[nx][ny] != 'O')continue;
                board[nx][ny]='Z';
                q.push({nx,ny});
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        bfs(board,m,n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')board[i][j]='X';
                else if(board[i][j]=='Z')board[i][j]='O';
            }
        }
    }
};
