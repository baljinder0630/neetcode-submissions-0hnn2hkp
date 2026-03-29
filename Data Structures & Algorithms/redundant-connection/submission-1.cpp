class Solution {
public:
    bool detectCycle(auto& adj,auto& visited,int node,int parent){
        if(visited.count(node))return true;
        visited.insert(node);
        for(auto it:adj[node]){
            if(it == parent)continue;
            if(detectCycle(adj,visited,it,node)){
                return true;
            }
        }
        visited.erase(node);
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+2);
        for(auto it:edges){
            unordered_set<int> visited;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            if(detectCycle(adj,visited,it[0],-1)){
                return {it[0],it[1]};
            }
        }
        return {};
    }
};
