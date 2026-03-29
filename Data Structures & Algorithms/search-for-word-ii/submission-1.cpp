class Solution {
public:
    bool dfs(int x,int y,int index,string& word,auto& board){
        if(word.size() == index)return true;
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != word[index])return false;
        int dirX[] = {1,-1,0,0};
        int dirY[] = {0,0,1,-1};
        board[x][y]='#';
        bool ans = false;
        for(int i = 0 ;i < 4 ;i++){
            int newX = dirX[i] + x;
            int newY = dirY[i] + y;
            ans = ans || dfs(newX,newY,index+1,word,board);
        }
        board[x][y]=word[index];
        return ans;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_map<char,vector<pair<int,int>>> adj;
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                adj[board[i][j]].push_back({i,j});
            }
        }
        vector<string> ans;
        for(int i = 0;i  < words.size(); i++){
            for(auto [x,y]:adj[words[i][0]]){ 
                if(dfs(x,y,0,words[i],board)){
                    ans.push_back(words[i]);
                    break;
                } 
            }
        }
        return ans;
    }
};
