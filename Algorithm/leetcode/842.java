//https://leetcode.com/problems/split-array-into-fibonacci-sequence/
//http://1ilsang.blog.me/221612773885

class Solution {
    public List<Integer> splitIntoFibonacci(String S) {
        List<Integer> ret = new ArrayList<>();
        go(S.toCharArray(), 0, ret);
        return ret;
    }
    
    private boolean go(char[] s, int curIdx, List<Integer> ret) {
        if(curIdx == s.length) return ret.size() >= 3;
        
        long n = 0;
        for(int i = curIdx; i < s.length; i++) {
            n = n * 10 + s[i] - '0';
            if(n > Integer.MAX_VALUE) return false;
            if(isPossible(s, (int)n, curIdx, i, ret)) {
                ret.add((int)n);
                if(go(s, i + 1, ret)) return true;
                ret.remove(ret.size() - 1);
            }
        }
        
        return false;
    }
    
    private boolean isPossible(char[] s, int n, int start, int cur, List<Integer> ret) {
        if(start != cur && s[start] == '0') return false;
        if(ret.size() < 2) return true;
        
        int i = ret.size() - 1;
        return ret.get(i) + ret.get(i - 1) == n;
    }
}
