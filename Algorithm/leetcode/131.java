//https://leetcode.com/problems/palindrome-partitioning/
//http://1ilsang.blog.me/221597878253

class Solution {
    boolean[][] isPalindrome;
    public List<List<String>> partition(String s) {
        List<List<String>> ret = new LinkedList<>();
        isPalindrome = getPalindromeArray(s.toCharArray());
        go(ret, new LinkedList<>(), s, s.length(), 0);
        return ret;
    }
    
    private void go(List<List<String>> origin, List<String> temp, String s, int len, int left) {
        if(left == len) {
            origin.add(new LinkedList<>(temp));
            return;
        }
        for(int i = left; i < len; i++) {
            if(isPalindrome[left][i]) {
                temp.add(s.substring(left, i + 1));
                go(origin, temp, s, len, i + 1);
                temp.remove(temp.size() - 1);
            }
        }
    }
    
    private boolean[][] getPalindromeArray(char[] s) {
        int len = s.length;
        boolean[][] ret = new boolean[len][len];
        for(int i = len - 1; i >= 0; i--) {
            for(int j = i; j < len; j++) {
                ret[i][j] = (s[i] == s[j]  && (j - i <= 2 || ret[i + 1][j - 1]));
            }
        }
        return ret;
    }
}
