/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    unordered_set<Node*> visited;
    Node* lowestCommonAncestor(Node* p, Node * q) {
        while(p || q){
            if(p){
                if(visited.count(p))return p;
                visited.insert(p);
                p = p->parent;
            }
            if(q){
                if(visited.count(q))return q;
                visited.insert(q);
                q = q->parent;
            }
        }
        return NULL;
    }
};