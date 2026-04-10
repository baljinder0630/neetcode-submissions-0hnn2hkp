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
    ListNode* reverseLL(ListNode* head,ListNode* prevNode,int dist){
        ListNode* curr= head;
        ListNode* next = head;
        ListNode* prev = NULL;
        // cout<<curr->val<<" "<<prev->val;
        while(dist-- && curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head -> next = next;
        if(prevNode)
            prevNode->next = prev;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int dist = right - left + 1;
        ListNode* temp = head;
        ListNode* prev = NULL;
        int start = left;
        while(--left && temp != NULL){
            prev = temp;
            temp = temp->next;
        }
        ListNode* ans = reverseLL(temp,prev,dist);
        if(start == 1)head = ans;
        return head;
    }
};