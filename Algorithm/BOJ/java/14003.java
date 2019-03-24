//https://www.acmicpc.net/problem/14003

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Node> sList = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        int n = Integer.parseInt(br.readLine());
        String[] tmp = br.readLine().split(" ");
        int[] arr = new int[n];
        int[] list = new int[n];
        int idx = 1;
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(tmp[i]);
        sList.add(new Node(0, arr[0]));
        list[0] = arr[0];
        for (int i = 1; i < n; i++) {
            if (list[idx - 1] < arr[i]) {
                list[idx++] = arr[i];
                sList.add(new Node(idx - 1, arr[i]));
            } else if (idx > 1 && list[idx - 2] < arr[i] && arr[i] < list[idx - 1]) {
                list[idx - 1] = arr[i];
                sList.add(new Node(idx - 1, arr[i]));
            } else {
                int l = 0;
                int r = idx;
                while (l < r) {
                    int mid = l + r >> 1;
                    if (list[mid] < arr[i]) l = mid + 1;
                    else r = mid;
                }
                list[r] = arr[i];
                sList.add(new Node(r, arr[i]));
            }
        }
        System.out.println(idx);
        int top = idx - 1;
        for(int i = n - 1 ; i >= 0;i--) {
            Node now = sList.get(i);
            if(now.i == top) {
                stack.push(now.v);
                top--;
            }
        }
        while(!stack.isEmpty()) System.out.print(stack.pop() + " ");
    }

    private static class Node {
        int i, v;

        public Node(int i, int v) {
            this.i = i;
            this.v = v;
        }
    }
}
