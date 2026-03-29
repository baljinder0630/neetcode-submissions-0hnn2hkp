class Solution {
public:
    void dfs(auto& adj,int node,auto& visited){
        visited.insert(node);
        for(auto it:adj[node]){
            if(!visited.count(it)){
                dfs(adj,it,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans =0;
        unordered_set<int> visited;
        for(int i = 0;i < n;i++){
            if(!visited.count(i)){
                dfs(adj,i,visited);
                ans++;
            }
        }
        return ans;
    }
};
