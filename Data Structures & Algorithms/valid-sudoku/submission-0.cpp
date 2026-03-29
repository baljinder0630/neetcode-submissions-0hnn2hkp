class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char> s;
            for(int j=0;j<9;j++){
                if(s.count(board[i][j]))return false;
                if(board[i][j] != '.')s.insert(board[i][j]);
            }
        }
        for(int j=0;j<9;j++){
            unordered_set<char> s;
            for(int i=0;i<9;i++){
                if(s.count(board[i][j]))return false;
                if(board[i][j] != '.')s.insert(board[i][j]);
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                unordered_set<char> s;
                for(int x = i; x < i+3; x++){
                    for(int y=j; y < j+3; y++){
                        if(s.count(board[x][y]))return false;
                        if(board[x][y] != '.')s.insert(board[x][y]);
                    }
                }
            }
        }
        return true;
    }
};
