class Solution {
    public void solve(List<List<Integer>> ans,List<Integer> temp,int index,int[] nums){
        if(index == nums.length){
            ans.add(new ArrayList<>(temp));
            return;
        }
        // not take
        solve(ans,temp,index+1,nums);
        temp.add(nums[index]);
        solve(ans,temp,index+1,nums);
        temp.remove(temp.size()-1);
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        solve(ans,temp,0,nums);
        return ans;
    }
}
