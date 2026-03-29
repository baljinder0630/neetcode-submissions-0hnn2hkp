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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head, *node=head;
        while(n--){
            temp=temp->next;
        }
        while(temp && temp->next){
            temp=temp->next;
            node=node->next;
        }
        if(node == head && temp == NULL)return node->next;
        if(node && node->next){
            node->next=node->next->next;
        }
        return head;
    }
};
