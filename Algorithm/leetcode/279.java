//https://leetcode.com/problems/perfect-squares/
//https://1ilsang.blog.me/221596499342

class Solution {
    public int numSquares(int n) {
        int[] memo = new int[n + 1];
        Arrays.fill(memo, Integer.MAX_VALUE);
        memo[0] = 0;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j * j <= i; j++)  {
                memo[i] = Math.min(memo[i - j * j] + 1, memo[i]);
            }
        }
        
        return memo[n];
    }
}
