//https://leetcode.com/problems/add-two-numbers/
//https://1ilsang.blog.me/221584961180

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ans = new ListNode(0);
        ListNode dump = ans;
        int carry = 0;
        
        while(l1 != null || l2 != null) {
            int a = l1 == null ? 0 : l1.val;
            int b = l2 == null ? 0 : l2.val;
            int now = a + b + carry;
            dump.next = new ListNode(now % 10);
            dump = dump.next;
            carry = now / 10;
            if(l1 != null) l1 = l1.next;
            if(l2 != null) l2 = l2.next;
        }
        if(carry > 0) dump.next = new ListNode(carry);
        
        return ans.next;
    }
}
