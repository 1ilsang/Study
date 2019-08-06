//https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
//https://1ilsang.blog.me/221607115938

class Solution {
    public int longestSubstring(String s, int k) {
        int ret = 0;
        int[] count = new int[26];
        char[] chr = s.toCharArray();
        boolean flag = true;
        
        for(int i = 0; i < chr.length; i++) count[chr[i] - 'a']++;
        for(int i = 0; i < chr.length; i++) {
            if(count[chr[i] - 'a'] > 0 && count[chr[i] - 'a'] < k) {
                chr[i] = '#';
                flag = false;
            }
        }
        if(flag) return chr.length;
        
        String[] str = new String(chr).split("#");
        for(String e: str) ret = Math.max(ret, longestSubstring(e, k));
        
        return ret;
    }
}
