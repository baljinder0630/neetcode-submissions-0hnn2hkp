class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> arr1(m,false);
        vector<bool> arr2(n,false);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    arr1[i] = true;
                    arr2[j] = true;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr1[i] || arr2[j]){
                    matrix[i][j] = 0;
                }
            }
        }

    }
};
