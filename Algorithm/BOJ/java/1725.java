//https://www.acmicpc.net/problem/1725

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

import static java.lang.Math.max;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<Integer> stack = new Stack<>();
        int n = Integer.parseInt(br.readLine());
        int[] histo = new int[n + 1];
        int ans = 0;
        int top;

        for(int i = 0; i <= n; i++) {
            if(i < n) histo[i] = Integer.parseInt(br.readLine());
            while(!stack.empty() && histo[stack.peek()] > histo[i]) {
                int bot;
                top = stack.peek();
                stack.pop();
                if(stack.empty()) bot = i;
                else bot = i - stack.peek() - 1;

                ans = max(ans, histo[top] * bot);
            }
            stack.push(i);
        }
        System.out.println(ans);
    }
}
