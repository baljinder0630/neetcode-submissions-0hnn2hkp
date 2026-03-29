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
        // l1 = reverseList(l1);
        // l2 = reverseList(l2);
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            ListNode* temp = new ListNode(sum % 10);
            carry = sum / 10;
            tail->next = temp;
            tail = temp;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            ListNode* temp = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry) / 10;
            tail->next = temp;
            tail = temp;
            l1 = l1->next;
        }
        while(l2 != NULL){
            ListNode* temp = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry) / 10;
            tail->next = temp;
            tail = temp;
            l2 = l2->next;
        }
        if(carry){
            tail -> next = new ListNode(carry);
        }
        // root = reverseList(root->next);
        return root->next;
    }
};
