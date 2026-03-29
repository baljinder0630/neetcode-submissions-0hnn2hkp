class DSU{
    vector<int> parent, size;
    public:
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int findParent(int node){
        if(parent[node] == node)return node;
        return parent[node] = findParent(parent[node]);
    }
    void unite(int a,int b){
        int p1 = findParent(a);
        int p2 = findParent(b);
        if(p1 == p2)return;
        if(size[p1] < size[p2])swap(p1,p2);
        parent[p2]=p1;
        size[p1]+=size[p2];
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][1]-points[j][1]) + abs(points[i][0] - points[j][0]);
                edges.push_back({dist,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        int ans = 0, count = 0;
        DSU dsu(n);
        for(auto it:edges){
            if(dsu.findParent(it[1]) != dsu.findParent(it[2])){
                ans += it[0];
                dsu.unite(it[1],it[2]);
                count++;
                if(count == n-1)return ans;
            }
        }
        return ans;
    
    }
};
