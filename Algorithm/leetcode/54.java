//https://leetcode.com/problems/spiral-matrix/
//https://1ilsang.blog.me/221588151803

class Solution {
    private int[] dr = {0,1,0,-1};
    private int[] dc = {1,0,-1,0};
    
    public List<Integer> spiralOrder(int[][] matrix) {
        LinkedList<Integer> ret = new LinkedList<>();
        if(matrix.length == 0) return ret;
        
        int n = matrix.length;
        int m = n > 0 ? matrix[0].length : 0;
        boolean[][] visit = new boolean[n][m];
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(0, 0, 0));
        int cnt = 0;
        
        while(!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            int d = queue.peek().d;
            ret.add(matrix[r][c]);
            visit[r][c] = true;
            cnt++;
            queue.poll();
            if(cnt == n * m) break;
            
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr < 0 || nc < 0 || nr >= n || nc >= m || visit[nr][nc]) {
                d += 1;
                if(d == 4) d = 0;
                nr = r + dr[d];
                nc = c + dc[d];
            }
            queue.offer(new Node(nr, nc, d));
        }

        return ret;
    }
    
    private class Node {
        int r, c, d;
        
        Node(int r, int c, int d) {
            this.r = r;
            this.c = c;
            this.d = d;
        }
    }
}
