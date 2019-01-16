//https://www.acmicpc.net/problem/9012

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for(int t = 0; t < n; t++) {
            Stack<Character> stack = new Stack<>();

            char[] str = br.readLine().toCharArray();
            stack.push(str[0]);
            for(int i = 1 ; i < str.length; i++) {
                if(stack.empty()) stack.push(str[i]);
                else if(stack.peek() == '(' && str[i] == ')') stack.pop();
                else stack.push(str[i]);
            }

            System.out.println(stack.empty() ? "YES" : "NO");
        }
    }
}
