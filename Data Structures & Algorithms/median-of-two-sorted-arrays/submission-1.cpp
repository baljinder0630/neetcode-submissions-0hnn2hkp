class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n)return findMedianSortedArrays(nums2,nums1);
        int l = 0, r = m;
        while(l <= r){
            int mid1 = ( l + r )/2;
            // mid1 + mid2 = (m+n+1)/2;
            int mid2 = (n+m+1)/2 - mid1;
            int left1 = mid1 == 0 ? -1e9 : nums1[mid1-1];
            int right1 = mid1 == m ? 1e9 : nums1[mid1]; 

            int left2 = mid2 == 0 ? -1e9 : nums2[mid2-1];
            int right2 = mid2 == n ? 1e9 : nums2[mid2]; 

            if(left1 < right2 && left2 < right1){
                if((m+n)%2 == 0)return (max(left1,left2) + min(right1,right2))/2.0;
                else return max(left1,left2);
            }
            else if(left1 > right2){
                r = mid1-1;
            }
            else l = mid1+1;
        }
        return 0;
    }
};
