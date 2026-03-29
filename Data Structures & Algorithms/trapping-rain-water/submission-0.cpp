class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);
        stack<int> s1,s2;
        for(int i=0; i<n; i++){
            while(!s1.empty() && s1.top() < height[i])s1.pop();
            if(s1.empty())leftMax[i]=0;
            else leftMax[i]=s1.top();
            if(s1.empty()||s1.top()<height[i])
            s1.push(height[i]);
        }
        for(int i=n-1; i>=0; i--){
            while(!s2.empty() && s2.top() <= height[i])s2.pop();
            if(s2.empty())rightMax[i]=0;
            else rightMax[i]=s2.top();
            if(s2.empty()||s2.top()<height[i])
            s2.push(height[i]);
        }
        int ans=0;
        for(int i = 0 ;i < n ; i++){
            ans += max(min(leftMax[i], rightMax[i]) - height[i],0);
            cout<<i<< " "<<leftMax[i]<< " "<<rightMax[i]<<endl;
        }
        return ans;
    }
};
