class DSU{
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findParent(int u){
        if(parent[u] == u)return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionAll(int u,int v){
        int p1 = findParent(u);
        int p2 = findParent(v);
        if(p1 == p2){
            return;
        }
        if(size[p1] < size[p2]){
            size[p2] += size[p1];
            parent[p1] = parent[p2];
        }
        else{
            size[p1] += size[p2];
            parent[p2] = parent[p1];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        DSU dsu(n);
        for(auto it:edges){
            if(dsu.findParent(it[0]) == dsu.findParent(it[1])){
                return it;
            }
            dsu.unionAll(it[0],it[1]);
        }
        return {};
    }
};
