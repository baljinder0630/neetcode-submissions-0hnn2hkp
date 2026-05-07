class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals,(a,b)-> Integer.compare(a[0],b[0]));
        List<int[]> output = new ArrayList<>();
        output.add(intervals[0]);
        for(int i=0;i<intervals.length;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            int[] lastEnd = output.get(output.size() -1);
            if(lastEnd[1] < start){
                output.add(new int[]{start,end});
            }
            else{
                output.get(output.size() - 1)[1] = Math.max(end,lastEnd[1]);
            }
        }
        return output.toArray(new int[output.size()][]);
    }
}
