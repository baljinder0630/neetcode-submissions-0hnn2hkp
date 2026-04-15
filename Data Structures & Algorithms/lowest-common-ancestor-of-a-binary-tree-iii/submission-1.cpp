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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* a = p,* b = q;
        while(p != q){
            p = p ? p->parent: a;
            q = q ? q->parent: b;
        }
        return q;
    }
};