class Solution {
    public void merge(int[] nums,int start,int mid, int end){
        int[] arr1 = new int[mid - start + 1];
        int[] arr2 = new int[end - mid];
        for(int i=start,j=0;i<=mid;i++,j++){
            arr1[j] = nums[i];
        }
        for(int i=mid+1,j=0;i<=end;i++,j++){
            arr2[j] = nums[i];
        }
        int k = start;
        int p1 = 0, p2 = 0;
        while(p1 < arr1.length && p2 < arr2.length){
            if(arr1[p1] < arr2[p2]){
                nums[k] = arr1[p1];
                p1++;
            }
            else{
                nums[k] = arr2[p2];
                p2++;
            }
            k++;
        } 
        while(p1 < arr1.length){
            nums[k] = arr1[p1];
            p1++;
            k++;
        } 
        while(p2 < arr2.length){
            nums[k] = arr2[p2];
            p2++;
            k++;
        } 
    }
    public void mergeSort(int[] nums,int start,int end){
        if(start >= end)return;
        int mid = (start + end) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        merge(nums,start,mid,end);
    }
    public int[] sortArray(int[] nums) {
        mergeSort(nums,0,nums.length - 1);
        return nums;
    }
}