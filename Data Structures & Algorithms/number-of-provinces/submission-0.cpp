class Solution {
public:
    void solve(int node,auto& adj,auto& visited,int n){
        if(visited.count(node))return;
        visited.insert(node);
        for(int i=0;i<n;i++){
            if(i == node)continue;
            if(adj[node][i] == 0)continue;
            solve(i,adj,visited,n);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        unordered_set<int> visited;
        for(int i=0;i<n;i++){
            if(visited.count(i))continue;
            solve(i,isConnected,visited,n);
            ans++;
        }
        return ans;
    }
};