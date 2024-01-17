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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null)   return null;

        int cur = 0;
        if (l1 != null) cur += l1.val;
        if (l2 != null) cur += l2.val;

        if (cur / 10 > 0) {
            if (l1 != null) {
                if (l1.next == null) {
                   l1.next = new ListNode(cur / 10);
                }
                else {
                    l1.next.val += cur / 10;
                }
            }
            else if (l2 != null) {
                if (l2.next == null) {
                   l2.next = new ListNode(cur / 10);
                }
                else {
                    l2.next.val += cur / 10;
                }
            }
        }

        if (l1 != null) l1 = l1.next;
        if (l2 != null) l2 = l2.next;

        return new ListNode(cur % 10, addTwoNumbers(l1, l2));
    }
}