//https://www.acmicpc.net/problem/5076

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            Stack<String> stack = new Stack<>();
            String str = br.readLine();
            if (str.equals("#")) break;
            if (!str.contains(">") && !str.contains("<")) {
                System.out.println("legal");
                continue;
            }
            String[] tags = str.split("<");

            for (int i = 1; i < tags.length; i++) {
                String tmp;
                if (tags[i].charAt(0) == '/') tmp = tags[i].substring(1, tags[i].indexOf(">"));
                else if (tags[i].charAt(0) == 'a' && tags[i].charAt(1) == ' ') tmp = "a";
                else if (tags[i].trim().equals("br />")) tmp = "br";
                else tmp = tags[i].substring(0, tags[i].indexOf(">"));

                if (stack.isEmpty() && !tmp.equals("br")) {
                    stack.push(tmp);
                } else if (!stack.isEmpty() && tmp.equals(stack.peek())) {
                    stack.pop();
                } else if (!tmp.equals("br")) stack.push(tmp);
            }

            if (stack.isEmpty()) System.out.println("legal");
            else System.out.println("illegal");
        }
        br.close();
    }
}
