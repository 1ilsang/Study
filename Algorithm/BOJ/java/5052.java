//https://www.acmicpc.net/problem/5052
//http://1ilsang.blog.me/221518648956

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 0; t < tcase; t++) {
            int n = Integer.parseInt(br.readLine());
            String[] list = new String[n];
            Trie trie = new Trie();
            boolean ans = true;

            for (int i = 0; i < n; i++) list[i] = br.readLine();
            Arrays.sort(list);

            for (int i = 0; i < n; i++) {
                if (!trie.insert(list[i])) {
                    ans = false;
                    break;
                }
            }

            System.out.println(ans ? "YES" : "NO");
        }
    }
}

class Trie {
    private TrieNode root;

    Trie() {
        root = new TrieNode();
    }

    boolean insert(String key) {
        TrieNode curNode = root;
        int length = key.length();

        for (int i = 0; i < length; i++) {
            char c = key.charAt(i);
            int next = c - '0';

            if (curNode.children[next] == null) {
                curNode.children[next] = new TrieNode();
            }

            curNode = curNode.children[next];

            if (curNode.isTerminal && i + 1 < length) return false;
        }

        curNode.isTerminal = true;
        return true;
    }
}

class TrieNode {
    TrieNode[] children = new TrieNode[10];
    boolean isTerminal;

    TrieNode() {
        isTerminal = false;
    }
}
