import java.util.*;
import java.io.*;

class Solve {
    int n;
    String[] words;

    private void getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        words = new String[n];
        for (int i = 0; i < n; i++) {
            words[i] = br.readLine();
        }
    }

    public void solve() throws IOException {
        getInput();

        Map<Character, Integer> charValueMap = new HashMap<>();

        for (String word : words) {
            int len = word.length();
            for (int j = 0; j < len; j++) {
                char ch = word.charAt(j);
                int value = (int) Math.pow(10, len - j - 1);
                charValueMap.put(ch, charValueMap.getOrDefault(ch, 0) + value);
            }
        }

        List<Integer> values = new ArrayList<>(charValueMap.values());
        values.sort(Collections.reverseOrder());

        int now = 9, ans = 0;
        for (int value : values) {
            ans += value * now;
            now--;
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Integer.toString(ans));
        bw.flush();
        bw.close();
    }
}

public class Main {
    public static void main(String args[]) throws IOException {
        Solve solve = new Solve();
        solve.solve();
    }
}
