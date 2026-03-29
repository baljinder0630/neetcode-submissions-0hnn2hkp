class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1)return false;
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            // indegree[it[1]]++;
        }
        queue<int> q;
        unordered_set<int> visited;
        q.push(0);
        visited.insert(0);
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto it:adj[front]){
                if(visited.count(it)){
                    continue;
                }
                visited.insert(it);
                q.push(it);
            }
        }
        return visited.size() == n;
    }
};
