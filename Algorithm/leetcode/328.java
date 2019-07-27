//https://leetcode.com/problems/odd-even-linked-list/submissions/
//https://1ilsang.blog.me/221597552829

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        ListNode odd = head;
        if(odd == null) return head;
        ListNode even = head.next;
        if(even == null || even.next == null) return head;
        go(head.next.next, odd, even, even, 3);
        return odd;
    }
    
    private void go(ListNode head, ListNode odd, ListNode even, ListNode firstEven, int depth) {
        if(head == null) {
            even.next = null;
            odd.next = firstEven;
            return;
        }
        if(depth % 2 == 0) {
            even.next = head;
            even = even.next;
        } else {
            odd.next = head;
            odd = odd.next;
        }
        go(head.next, odd, even, firstEven, depth + 1);
    }
}
