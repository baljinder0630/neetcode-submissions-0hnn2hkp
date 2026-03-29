class Solution {
    int cycleStart;
    unordered_set<int> cycle;
public:
    bool detectCycle(auto& adj,auto& visited,int node,int parent){
        if(visited.count(node)){
            cycleStart = node;
            return true;
        }
        visited.insert(node);
        for(auto it:adj[node]){
            if(it == parent)continue;
            if(detectCycle(adj,visited,it,node)){
                if(cycleStart != -1)cycle.insert(node);
                if(cycleStart == node)cycleStart = -1;
                return true;
            }
        }
        visited.erase(node);
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+2);
        unordered_set<int> visited;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        cycleStart = -1;
        if(!detectCycle(adj,visited,1,-1)){
            return {};
        }
        for(int i=edges.size()-1;i>=0;i--){
            if(cycle.count(edges[i][0]) && cycle.count(edges[i][1])){
                return edges[i];
            }
        }
        return {};
    }
};
