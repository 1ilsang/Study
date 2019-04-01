//https://www.acmicpc.net/problem/7785
//http://1ilsang.blog.me/221502915637

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private final static int D = 31;
    private final static int BUCKET_SIZE = (int) 1e6 + 9;
    private final static int MOD = BUCKET_SIZE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        MyHash hash = new MyHash();
        for(int i = 0 ; i < n; i++) {
            String[] tmp = br.readLine().split(" ");
            int key = hash.getHashCode(tmp[0]);
            if(tmp[1].equals("enter")) hash.add(key, tmp[0]);
            else hash.remove(key, tmp[0]);
        }
        LinkedList<String> ans = hash.getAllValues();
        Collections.sort(ans, Collections.reverseOrder());
        for(String e: ans) System.out.println(e);
    }

    private static class MyHash {
        private Node[] arr;

        MyHash() {
            arr = new Node[BUCKET_SIZE];
        }
        int getHashCode(String name) {
            int ret = 0;
            for (int i = 0; i < name.length(); i++) {
                ret = (ret * D + name.charAt(i)) % MOD;
                if (ret < 0) ret += MOD;
            }
            return ret;
        }

        void add(int key, String value) {
            if (arr[key] == null) arr[key] = new Node(value);
            else {
                Node tmp = arr[key];
                while(tmp.next != null) tmp = tmp.next;
                tmp.next = new Node(value);
            }
        }

        void remove(int key, String value) {
            if (arr[key] == null) return;
            Node tmp = arr[key];
            if (tmp.value.equals(value)) {
                arr[key] = arr[key].next;
                return;
            }
            while (tmp.next != null) {
                if (tmp.next.value.equals(value)) {
                    Node tmp2 = tmp.next;
                    tmp.next = tmp.next.next;
                    tmp2.next = null;
                    break;
                } else tmp = tmp.next;
            }
        }
        LinkedList<String> getAllValues() {
            LinkedList<String> ret = new LinkedList<>();
            for(Node e: arr) {
                if(e != null) {
                    ret.add(e.value);
                    while (e.next != null) {
                        ret.add(e.next.value);
                        e = e.next;
                    }
                }
            }
            return ret;
        }

        LinkedList<String> getValue(int key) {
            if (arr[key] == null) return null;
            Node tmp = arr[key];
            LinkedList<String> ret = new LinkedList<>();
            ret.add(tmp.value);
            while (tmp.next != null) {
                ret.add(tmp.next.value);
                tmp = tmp.next;
            }
            return ret;
        }
    }

    private static class Node {
        String value;
        Node next;

        public Node(String value) {
            this.value = value;
            this.next = null;
        }
    }
}
