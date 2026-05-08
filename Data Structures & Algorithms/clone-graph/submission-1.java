/*
Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    HashMap<Node,Node> cache = new HashMap<>();
    public Node cloneGraph(Node node) {
        if(node == null)return null;
        if(cache.containsKey(node))return cache.get(node);
        
        Node root = new Node(node.val);
        cache.put(node,root);
        root.neighbors = new ArrayList<>();
        for(Node nei:node.neighbors){
            root.neighbors.add(cloneGraph(nei));
        }
        return root;
    }
}