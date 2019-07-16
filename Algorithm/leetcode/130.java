//https://leetcode.com/problems/surrounded-regions
//http://1ilsang.blog.me/221587201701

class Solution {
    private int n, m;
    private char[][] area;
    private boolean[][] visit;
    private final int[] dr = {0,1,0,-1};
    private final int[] dc = {1,0,-1,0};
    
    public void solve(char[][] board) {
        n = board.length;
        if(n > 0) m = board[0].length;
        else m = 0;
        area = board;
        visit = new boolean[n][m];
        
        for(int  i = 0 ; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(visit[i][j] || board[i][j] == 'X') continue;
                setArea(i, j);
            }
        }
    }
    private void setArea(int i, int j) {
        Queue<Node> queue = new LinkedList<>();
        LinkedList<Node> list = new LinkedList<>();
        boolean isEdge = false;
        
        queue.offer(new Node(i, j));
        list.add(new Node(i, j));
        visit[i][j] = true;
        
        while(!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            queue.poll();
            
            if(r == 0 || r == n - 1 || c == 0 || c == m - 1) isEdge = true;
            
            for(int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m || visit[nr][nc] || area[nr][nc] == 'X') continue;
                queue.offer(new Node(nr, nc));
                list.add(new Node(nr, nc));
                visit[nr][nc] = true;
            }
        }
        
        if(isEdge) return;
        for(Node e: list) area[e.r][e.c] = 'X';
    }
    
    private static class Node {
        int r, c;
        Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
}
