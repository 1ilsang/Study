//https://leetcode.com/problems/unique-paths/
//https://1ilsang.blog.me/221584396997

class Solution {
    public int uniquePaths(int m, int n) {
        int[][] area = new int[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i==0 || j == 0) area[i][j] = 1;
                else area[i][j] = area[i-1][j] + area[i][j-1];
            }
        }
        return area[n-1][m-1];
    }
}
