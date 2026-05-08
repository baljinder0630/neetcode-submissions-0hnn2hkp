class Solution {
    public void solve(int[] nums,int target,List<List<Integer>> ans,List<Integer> temp,int index){
        if(target == 0){
            ans.add(new ArrayList<>(temp));
            return;
        }
        for(int i = index; i < nums.length; i++){
            if(i > index && nums[i] == nums[i-1])continue;
            if(nums[i] <= target){
                temp.add(nums[i]);
                solve(nums,target-nums[i],ans,temp,i+1);
                temp.remove(temp.size()-1);
            }
        }
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        solve(candidates,target,ans,temp,0);
        return ans;
    }
}
