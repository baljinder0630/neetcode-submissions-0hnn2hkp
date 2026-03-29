class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indegree[i] == 1){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            indegree[front]--;
            for(auto it:adj[front]){
                indegree[it]--;
                if(indegree[it] == 1){
                    q.push(it);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            if(indegree[edges[i][0]] == 2 && indegree[edges[i][1]]){
                return edges[i];
            }
        }
        return {};
    }
};
