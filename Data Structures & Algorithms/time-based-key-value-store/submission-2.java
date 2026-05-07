class TimeMap {
    HashMap<String,List<Pair<Integer,String>>> mp;
    public TimeMap() {
        mp = new HashMap<>();
    }

    public void set(String key, String value, int timestamp) {
        mp.putIfAbsent(key,new ArrayList<>());
        mp.get(key).add(new Pair<>(timestamp,value));
    }

    public String get(String key, int timestamp) {
        if(!mp.containsKey(key))return "";
        List<Pair<Integer,String>> l = mp.get(key);
        int s = 0, e = l.size()-1;
        while(s <= e){
            int mid = (s + e)/2;
            if(l.get(mid).getKey() == timestamp)return l.get(mid).getValue();
            else if(l.get(mid).getKey() > timestamp){
                e = mid - 1;
            }
            else{
                s = mid+1;
            }
        }
                if(e < 0) return "";

        return l.get(e).getValue();
    }
}
