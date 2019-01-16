//https://www.acmicpc.net/problem/1935

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    private static Stack<Double> stackNum = new Stack<>();

    private static void calc(char op) {
        double b = stackNum.pop();
        double a = stackNum.pop();
        double ret;
        if(op == '+') ret = a + b;
        else if(op == '-') ret = a - b;
        else if(op == '/') ret = a / b;
        else ret = a * b;
//        System.out.println("op:" + op + ", ret: " + ret);
        stackNum.push(ret);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        char[] str = br.readLine().toCharArray();

        double[] arr = new double[n];
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(br.readLine());

        for (int i = 0; i < str.length; i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                stackNum.push(arr[str[i] - 'A']);
            }  else calc(str[i]);
        }

        System.out.printf("%.2f\n", Math.floor(stackNum.pop() * 100) / 100.0);
    }
}
