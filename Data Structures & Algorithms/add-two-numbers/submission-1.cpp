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
    ListNode* reverseList(ListNode* head){
        if(head==NULL || head->next == NULL)return head;
        ListNode* root = reverseList(head->next);
        head->next->next = head;
        head->next=NULL;
        return root;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(-1);
        ListNode* tail = root;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != 0){
            int sum = carry;
            if(l1){
                sum += l1->val;
                l1=l1->next;
            }
            if(l2){
                sum += l2->val;
                l2=l2->next;
            }
            ListNode* temp = new ListNode(sum % 10);
            carry = sum / 10;
            tail->next = temp;
            tail = temp;
        }
        
        return root->next;
    }
};
