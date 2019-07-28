//https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/
//http://1ilsang.blog.me/221597940371

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    private boolean flag = false;
    private int cnt = 0;
    
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head.next == null && n == 1) return null;
        go(head, 1, n);
        return flag ? head.next : head;
    }
    
    private ListNode go(ListNode cur, int depth, int n) {
        if(cur.next == null) {
            flag = true;
            cnt = depth;
            return cur;
        }
        ListNode ret = go(cur.next, depth +  1, n);
        if(flag && cnt - depth == n) {
            flag = false;
            cur.next = ret.next;
        }
        
        return cur;
    }
}
