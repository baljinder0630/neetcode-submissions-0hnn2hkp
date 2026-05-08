class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> visited = new HashSet<>(Arrays.asList(deadends));
        if(visited.contains("0000"))return -1;
        Queue<Pair> q = new ArrayDeque<>();
        q.offer(new Pair("0000",0));
        visited.add("0000");
        while(!q.isEmpty()){
            Pair front = q.poll();
            String curr = front.str;
            int step = front.steps;
            if(curr.equals(target))return step;
            for(int i=0;i<4;i++){
                StringBuilder s = new StringBuilder(curr);
                char ch = s.charAt(i);
                s.setCharAt(i, ch == '0' ? '9' : (char)(ch-1));
                if(!visited.contains(s.toString())){
                    visited.add(s.toString());
                    q.offer(new Pair(s.toString(),step+1));
                }
                s = new StringBuilder(curr);
                s.setCharAt(i, ch == '9' ? '0' : (char) (ch+1));
                if(!visited.contains(s.toString())){
                    visited.add(s.toString());
                    q.offer(new Pair(s.toString(),step+1));
                }
            }
        }
        return -1;
    }
}

class Pair{
    String str;
    int steps;
    Pair(String s,int step){
        str = s;
        steps = step;
    }
}