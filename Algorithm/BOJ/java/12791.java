//https://www.acmicpc.net/problem/12791
//http://1ilsang.blog.me/221502800659

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
        hash.add(1967, "DavidBowie");
        hash.add(1969, "SpaceOddity");
        hash.add(1970, "TheManWhoSoldTheWorld");
        hash.add(1971, "HunkyDory");
        hash.add(1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars");
        hash.add(1973, "AladdinSane");
        hash.add(1973, "PinUps");
        hash.add(1974, "DiamondDogs");
        hash.add(1975, "YoungAmericans");
        hash.add(1976, "StationToStation");
        hash.add(1977, "Low");
        hash.add(1977, "Heroes");
        hash.add(1979, "Lodger");
        hash.add(1980, "ScaryMonstersAndSuperCreeps");
        hash.add(1983, "LetsDance");
        hash.add(1984, "Tonight");
        hash.add(1987, "NeverLetMeDown");
        hash.add(1993, "BlackTieWhiteNoise");
        hash.add(1995, "1.Outside");
        hash.add(1997, "Earthling");
        hash.add(1999, "Hours");
        hash.add(2002, "Heathen");
        hash.add(2003, "Reality");
        hash.add(2013, "TheNextDay");
        hash.add(2016, "BlackStar");

        for (int i = 0; i < n; i++) {
            String[] tmp = br.readLine().split(" ");
            int start = Integer.parseInt(tmp[0]);
            int end = Integer.parseInt(tmp[1]);
            LinkedList<Node2> list = new LinkedList<>();
            for (int j = start; j <= end; j++) {
                LinkedList<String> tmpList = hash.getValues(j);
                if (tmpList != null) for (String e : tmpList) list.add(new Node2(j, e));
            }
            System.out.println(list.size());
            if(list.size() > 0) {
                for (Node2 e : list) {
                    System.out.println(e.key + " " + e.value);
                }
            }
        }
    }

    private static void quickSort(String[] arr, int left, int right) {
        if (left >= right) return;
        int l = left;
        int r = right + 1;
        // TODO Random Pivot :: MyRandom() - 0, 1
//        int pivot = (int) (Math.random() * (right - left + 1)) + left;
//        int pivot = left;
//        swap(arr, l, pivot);
        while (l < r) {
            do {
                l++;
            } while (l <= right && compare(arr[l], arr[left], 0));
            do {
                r--;
            } while (r > left && compare(arr[r], arr[left], 1));
            if (l < r) swap(arr, l, r);
        }
        swap(arr, r, left);
        quickSort(arr, left, r - 1);
        quickSort(arr, r + 1, right);
    }

    private static boolean compare(String a, String b, int flag) {
        if (a.length() > b.length()) {
            String tmp = a;
            a = b;
            b = tmp;
        }
        for (int i = 0; i < a.length(); i++) {
            int an = a.charAt(i);
            int bn = b.charAt(i);
            if (flag == 0 && an > bn) return true;
            else if (flag == 0 && an < bn) return false;
            if (flag == 1 && an < bn) return true;
            else if (flag == 1 && an > bn) return false;
        }
        return true;
    }

    private static void swap(String[] arr, int a, int b) {
        String tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    private static int getHashCode(String name) {
        int ret = 0;
        for (int i = 0; i < name.length(); i++) {
            ret = (ret * D + name.charAt(i)) % MOD;
            if (ret < 0) ret += MOD;
        }
        return ret;
    }

    private static class MyHash {
        private Node[] arr;
        private int size = 0;

        MyHash() {
            arr = new Node[BUCKET_SIZE];
        }

        void add(int key, String value) {
            if (arr[key] == null) arr[key] = new Node(value);
            else arr[key].next = new Node(value);
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

        LinkedList<String> getValues(int key) {
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

        public void setNext(Node next) {
            this.next = next;
        }

        public Node getNext() {
            return this.next;
        }
    }
    private static class Node2{
        int key;
        String value;

        public Node2(int key, String value) {
            this.key = key;
            this.value = value;
        }
    }
}
