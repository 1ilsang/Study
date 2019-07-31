//https://leetcode.com/problems/merge-intervals/
//https://1ilsang.blog.me/221600787510

class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals.length  == 0) return new int[][] {};
        
        LinkedList<int[]> list = new LinkedList<>();
        Arrays.sort(intervals, (a,b) -> Integer.compare(a[0], b[0]));
        int pin = 0;
        list.add(intervals[0]);
        
        for(int i = 1; i < intervals.length; i++) {
            if(list.peekLast()[1] >= intervals[i][0]) list.peekLast()[1] = Math.max(list.peekLast()[1], intervals[i][1]);
            else list.add(intervals[i]);
        }
        
        return list.toArray(new int[list.size()][]);
    }
}
