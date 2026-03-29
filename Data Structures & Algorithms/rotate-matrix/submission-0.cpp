class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose + reverse
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0;i<m-1;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(auto& it:matrix){
            reverse(it.begin(),it.end());
        }
    }
};
