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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return NULL;
        ListNode* root = lists[0];
        for(int i=1;i<lists.size();i++){
            root=merge(lists[i],root);
        }
        return root;
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* root= new ListNode(-1);
        ListNode* tail=root;
        while(l1 || l2){
            if(!l1){
                tail->next=l2;
                return root->next;
            }
            else if(!l2){
                tail->next=l1;
                return root->next;
            }
            else if(l1->val < l2->val){
                tail->next = l1;
                tail=tail->next;
                l1=l1->next;
            }
            else{
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            }
        }
        return root->next;
    }
};
