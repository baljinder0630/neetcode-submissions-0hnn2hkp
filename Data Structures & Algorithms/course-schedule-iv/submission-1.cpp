class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& arr, vector<vector<int>>& queries) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        for(auto it:arr){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i = 0 ; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        unordered_map<int,unordered_set<int>> pre;
        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto it:adj[front]){
                pre[it].insert(front);
                for(auto x : pre[front]){
                    pre[it].insert(x);
                }
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        vector<bool> ans;
        for(auto it:queries){
            if(pre[it[1]].count(it[0]))ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};