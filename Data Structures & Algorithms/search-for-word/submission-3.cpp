class Solution {
public:
    bool dfs(auto& board,string& word,int x,int y,int index){
        if(index == word.size())return true;
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return false;
        if(word[index] != board[x][y])return false;
        board[x][y] = '*';
        int dirX[] = {1,-1,0,0};
        int dirY[] = {0,0,-1,1};
        for(int i=0;i<4;i++){
            int newX = dirX[i] + x;
            int newY = dirY[i] + y; 
            if(dfs(board,word,newX,newY,index+1)){
                return true;
            }
        }
        board[x][y] = word[index];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    if(dfs(board,word,i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
