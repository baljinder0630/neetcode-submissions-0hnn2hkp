class DSU{
private:
    vector<int> size, parent;
public:
    DSU(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0; i<n; i++)
            parent[i]=i;
    }

    int findParent(int node){
        if(parent[node] == node)return node;
        return parent[node] = findParent(parent[node]); // path compression
    }

    bool isConnected(int u,int v){
        return findParent(u) == findParent(v);
    }

    void unionBySize(int u,int v){
        int pu = findParent(u), pv = findParent(v);
        if(pu == pv)return;
        if(size[pu] < size[pv]){
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        else{
            size[pu] += size[pv];
            parent[pv] = pu;
        }
    }
};
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        DSU dsu((m*n)+1);
        int dirX[] = {-1,1,0,0};
        int dirY[] = {0,0,1,-1};
        for(int i=0;i < m;i++){
            for(int j=0;j < n ; j++){
                if(board[i][j] != 'O')continue;
                if( i == 0 || j == 0 || i == m-1 || j == n-1){
                    dsu.unionBySize(m*n,n*i+j);
                }
                else{
                    for(int x=0;x < 4;x++){
                        int nx = i+dirX[x];
                        int ny = j+dirY[x];
                        if(board[nx][ny] == 'O'){
                            dsu.unionBySize(n*nx + ny, n*i + j);
                        }
                    }
                }
            }
        }
        for(int i=0; i < m ; i++){
            for(int j=0; j < n ; j++){
                if(board[i][j] == 'O' && !dsu.isConnected(i*n+j,m*n))board[i][j]='X';
            }
        }
    }
};
