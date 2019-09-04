//https://leetcode.com/problems/implement-trie-prefix-tree/
//https://1ilsang.blog.me/221612962217

class Trie {
    private TrieNode root;
    private final int BUCKET_SIZE = 26;
    
    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode cur = root;
        int len = word.length();
        
        for(int i = 0; i < len; i++) {
            int curIdx = word.charAt(i) - 'a';
            if(cur.next[curIdx] == null) cur.next[curIdx] = new TrieNode();
            cur = cur.next[curIdx];
        }
        
        cur.hit = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode cur = root;
        int len = word.length();
        
        for(int i = 0; i < len; i++) {
            int curIdx = word.charAt(i) - 'a';
            if(cur.next[curIdx] == null) return false;
            cur = cur.next[curIdx];
        }
                
        return cur.hit ? true : false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode cur = root;
        int len = prefix.length();
        
        for(int i = 0; i < len; i++) {
            int curIdx = prefix.charAt(i) - 'a';
            if(cur.next[curIdx] == null) return false;
            cur = cur.next[curIdx];
        }
        
        return true;
    }
    
    private class TrieNode {
        TrieNode[] next;
        boolean hit;
        
        TrieNode() {
            next = new TrieNode[BUCKET_SIZE];
        }
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
