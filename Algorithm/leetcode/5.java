//https://leetcode.com/problems/longest-palindromic-substring/
//https://1ilsang.blog.me/221615516179

class Solution {
    public String longestPalindrome(String s) {
        String ret = "";
        char[] chr = s.toCharArray();
        boolean[][] dp = new boolean[chr.length][chr.length];
        int maxN = 0;
        
        for(int i = chr.length - 1; i >= 0; i--) {
            for(int j = i; j < chr.length; j++) {
                dp[i][j] = (chr[i] == chr[j] && (j - i <= 2 || dp[i + 1][j - 1]));
                if(dp[i][j] && j - i >= maxN) {
                    maxN = j - i;
                    ret = s.substring(i, j + 1);
                }
            }
        }
        
        return ret;
    }
}
