class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // unique ids to all emails
        // accountId to emailId
        // adj matrix
        // bfs
        unordered_map<string,int> emailIds;
        unordered_map<int,string> emailMapping;
        unordered_map<int,int> accountIds;
        int id = 0;
        for(int accountId=0;accountId < accounts.size();accountId++){
            auto& account = accounts[accountId];
            for(int i=1;i<account.size();i++){
                if(!emailIds.count(account[i])){
                    emailIds[account[i]]=id;
                    emailMapping[id]=account[i];
                    accountIds[id]=accountId;
                    id++;
                }
            }
        }
        unordered_map<int ,vector<int>> adj;
        for(auto account:accounts){
            for(int i=2;i<account.size();i++){
                adj[emailIds[account[i]]].push_back(emailIds[account[i-1]]);
                adj[emailIds[account[i-1]]].push_back(emailIds[account[i]]);
            }
        }
        queue<int> q;
        unordered_set<int> visited;
        unordered_map<int,vector<int>> res;
        for(int i=0;i < id; i++){   
            if(visited.count(i))continue;
            q.push(i);
            visited.insert(i);
            int accountId = accountIds[i];
            // cout<<endl << accountId << ": ";
            while(!q.empty()){
                int front = q.front();
                q.pop();
                // cout<<front << " ";
                res[accountId].push_back(front);
                for(auto it:adj[front]){
                    if(!visited.count(it)){
                        q.push(it);
                        visited.insert(it);
                    }
                }
            }
        }
        vector<vector<string>> ans;
        for(auto it:res){
            vector<string> temp;
            temp.push_back(accounts[it.first][0]);
            cout<<it.first<<":";
            for(auto id:it.second){
                cout<<id<<" ";
                temp.push_back(emailMapping[id]);
            }
            cout<<endl;
            sort(temp.begin()+1,temp.end());
            if(temp.size() > 1)
                ans.push_back(temp);
        }
        return ans;
    }
};