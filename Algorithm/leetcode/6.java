//https://leetcode.com/problems/zigzag-conversion/
//https://1ilsang.blog.me/221585391817

class Solution {
    public String convert(String s, int numRows) {
        String ret = "";
        boolean flag = true;
        int cnt = 0;
        Node[] list = new Node[numRows];
        for(int i = 0 ; i < list.length; i++) list[i] = new Node('h');
        
        for(int i = 0 ; i < s.length(); i++) {
            Node dump = list[cnt];
            while(dump.next != null) dump = dump.next;
            dump.next = new Node(s.charAt(i));
            
            cnt += flag ? 1 : -1;
            if(cnt == numRows) {
                flag = false;
                cnt = cnt - 2 >= 0 ? cnt - 2 : 0;
            } else if(cnt == -1) {
                flag = true;
                cnt = cnt + 2 < numRows ? cnt + 2 :  numRows - 1;
            }
        }
        
        for(int i = 0; i < numRows; i++) {
            list[i] = list[i].next;
            while(list[i] != null) {
                ret += list[i].str;
                list[i] = list[i].next;
            }
        }
        return ret;
    }
    
    private class Node {
        char str;
        Node next;
        Node(char str) {
            this.str = str;
        }
    }
}
