//https://www.acmicpc.net/problem/11722

import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        Stack<Integer> stack = new Stack<>();
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];
        
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            while(!stack.empty()) {
                if(arr[stack.peek()] > arr[i]) {
                    sb.append(stack.peek());
                    break;
                }
                stack.pop();
            }
            if(stack.empty()) sb.append(0);
            stack.push(i);
            if(i != n) sb.append(" ");
        }
        System.out.print(sb);
        br.close();
    }
}
