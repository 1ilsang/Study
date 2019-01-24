//https://www.acmicpc.net/problem/1764
//https://github.com/1ilsang/Study

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] tmp = br.readLine().split(" ");
        int n = Integer.parseInt(tmp[0]);
        int m = Integer.parseInt(tmp[1]);
        ArrayList<String> list = new ArrayList<>();
        Set<String> set = new HashSet<>();

        for (int i = 0; i < n; i++) set.add(br.readLine());
        for (int i = 0; i < m; i++) {
            String str = br.readLine();
            if(set.contains(str)) list.add(str);
        }
        Collections.sort(list);

        System.out.println(list.size());
        for(String e: list) bw.write(e + "\n");

        br.close();
        bw.close();
    }
}
