/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null)return head;
        ListNode curr = head;
        ListNode node = head;
        while(n > 0){
            node = node.next;
            n--;
        }
        while(node != null && node.next != null){
            curr = curr.next;
            node = node.next;
        }
        if(curr == head && node == null)return curr.next;
        if(curr != null && curr.next != null){
            curr.next = curr.next.next;
        }
        return head;
    }
}
