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
    ListNode* split(ListNode* head){
        if(head==NULL|| head->next==NULL)return NULL;
        ListNode* fast=head, *slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* head2=slow->next;
        slow->next=NULL;
        return head2;
    }
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL)return head;
        ListNode* root = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return root;
    }
    void reorderList(ListNode* head) {
        ListNode* head2= split(head);
        head2 = reverse(head2);
        ListNode* temp=head;
        while(head != NULL && head2 != NULL){
            temp=head->next;
            head->next=head2;
            head2=head2->next;
            head->next->next=temp;
            head=temp;
        }
    }
};
// 1 
// 4





