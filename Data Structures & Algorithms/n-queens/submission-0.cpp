class Solution {
public:
    void solve(int index,int n,auto& temp,auto& ans){
        if(index == n){
            ans.push_back(temp);
            return;
        }
        for(int j = 0; j < n; j++){
            int i = index, k = j;
            bool isValid = true;
            while(i >= 0){
                if(temp[i][j] != '.')isValid = false;
                i--;
            }
            i = index;
            while(i >= 0 && k >= 0){
                if(temp[i][k] != '.')isValid = false;
                i--, k--;
            }
            k = j, i = index;
            while(i >= 0 && k < n){
                if(temp[i][k] != '.')isValid = false;
                i--;
                k++;
            }
            if(isValid){
                temp[index][j] = 'Q';
                solve(index+1,n,temp,ans);
                temp[index][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n,string(n, '.'));
        solve(0,n,temp,ans);
        return ans;
    }
};
