//https://leetcode.com/problems/rotate-image/
//https://1ilsang.blog.me/221592343576

class Solution {
    private int n;
    
    public void rotate(int[][] matrix) {
        n = matrix.length;
        for(int i = 0; i < 3; i++) go(matrix, 0, i);
    }
    
    private void swap(int[][] matrix, int r1, int c1, int r2, int c2) {
        matrix[r1][c1] = matrix[r1][c1] ^ matrix[r2][c2];
        matrix[r2][c2] = matrix[r1][c1] ^ matrix[r2][c2];
        matrix[r1][c1] = matrix[r1][c1] ^ matrix[r2][c2];
    }
    
    private void go(int[][] matrix, int cur, int direction) {
        if(cur == n / 2) return;
        
        for(int i = cur; i < n - 1 - cur; i++) {
            if(direction == 0) swap(matrix, cur, i, i, n - 1 - cur);
            else if(direction == 1) swap(matrix, i, cur, n - 1 - cur, i);
            else {
                if(i == cur) continue;
                swap(matrix, cur, i, n - cur - 1, n - 1 - i);
            }
        }
        
        if(direction == 0) swap(matrix, cur, cur, n - 1 - cur, n - 1 - cur);

        go(matrix, cur + 1, direction);
    }
}
