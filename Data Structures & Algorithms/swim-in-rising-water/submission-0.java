class DSU{
    public int[] parent;
    public int[] size;
    public DSU(int n){
        parent = new int[n];
        for(int i=0;i<n;i++)parent[i]=i;
        size = new int[n];
        for(int i=0;i<n;i++)size[i]=1;
    }
    public int findParent(int node){
        if(parent[node] == node)return node;
        return parent[node] = findParent(parent[node]);
    }

    public boolean unionAll(int a,int b){
        int p1 = findParent(a);
        int p2 = findParent(b);
        if(p1 == p2)return false;
        if(size[p1] < size[p2]){
            size[p2] += size[p1];
            parent[p1] = p2;
        }
        else{
            size[p1] += size[p2];
            parent[p2] = p1;
        }
        return true;
    }

    public boolean connected(int a,int b){
        return findParent(a) == findParent(b);
    }
}
class Edge{
    public int tide;
    public int x;
    public int y;

    public Edge(int tide,int x,int y){
        this.tide= tide;
        this.x=x;
        this.y=y;
    }
}
class Solution {
    public int swimInWater(int[][] grid) {
        int N = grid.length;
        List<Edge> positions = new ArrayList<>();
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                Edge e = new Edge(grid[i][j],i,j);
                positions.add(e);
            }
        }
        Collections.sort(positions, (a,b)->a.tide - b.tide);
        int[][] dir = {
            {0,1},{1,0},{0,-1},{-1,0}
        };
        DSU dsu = new DSU(N * N);
        for(Edge pos:positions){
            int x = pos.x, y = pos.y, tide = pos.tide;
            for(int i=0;i<4;i++){
                int newX = x + dir[i][0];
                int newY = y + dir[i][1];
                if(newX >= 0 && newX < N && newY >= 0 && newY < N && grid[newX][newY] <= tide){
                    dsu.unionAll(x*N + y, newX*N + newY);
                }
            }
            if(dsu.connected(0,N*N-1))return tide;
        }
        return  N*N;
    }
}
