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
        if (l1 == null && l2==null) {
            return null;
        }
        else if (l1 == null && l2 != null) {
            if (l2.val > 9) {
                if(l2.next != null) {
                   l2.next.val += 1;
                }
                else {
                    l2.next = new ListNode(1);
                }
                l2.val %= 10;
            }

            return new ListNode(l2.val, addTwoNumbers(null, l2.next));
        }
        else if (l1 != null && l2 == null) {
            if (l1.val > 9) {
               if (l1.next != null) {
                    l1.next.val += 1;
                }
                else {
                    l1.next = new ListNode(1);
                }
                l1.val %= 10;
            }
            
            return new ListNode(l1.val, addTwoNumbers(l1.next, null));
        }

        int cur = l1.val + l2.val;

        if (cur / 10 > 0) {
            if (l1.next != null) {
                l1.next.val += 1;
            }
            else if(l2.next != null) {
                l2.next.val += 1;
            }
            else {
                l1.next = new ListNode(1);
            }
        }

        ListNode node = new ListNode(cur % 10, addTwoNumbers(l1.next, l2.next));
        return node;
    }
}