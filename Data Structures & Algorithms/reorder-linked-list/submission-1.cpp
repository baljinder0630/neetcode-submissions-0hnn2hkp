/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* solve(ListNode* root,ListNode* curr){
        if(curr == NULL)return root;
        root = solve(root, curr->next);
        if(root == NULL)return root;
        ListNode* temp = NULL;
        if(root==curr||root->next==curr){
            curr->next=NULL;
        }
        else{
            temp=root->next;
            root->next=curr;
            curr->next=temp;
        }
        return temp;
    }
    void reorderList(ListNode* head) {
        solve(head, head->next);
    }
};
