class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)return {0};
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        // for(auto it:indegree){
        //     cout<<it<< " " ;
        // }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 1){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int size = q.size();
            ans.clear();
            while(size--){
                int front = q.front();
                ans.push_back(front);
                q.pop();
                for(auto it:adj[front]){
                    indegree[it]--;
                    if(indegree[it] == 1)q.push(it);
                }
            }
        }
        return ans;
    }
};