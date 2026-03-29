class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, right = n-1, bottom = m-1, left = 0;
        vector<int> ans;
        while(top <= bottom && left <= right){
            cout<<left << " "<< top << " "<< bottom << " " << right<<endl;
            for(int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            for(int j = top+1;j <= bottom; j++){
                ans.push_back(matrix[j][right]);
            }
            if(top < bottom)
            for(int i = right-1; i >= left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            if(left < right)
            for(int i = bottom-1; i > top; i--){
                ans.push_back(matrix[i][left]);
            }
            top++;
            left++;
            right--;
            bottom--;
        }
        return ans;
    }
};
