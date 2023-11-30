import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class Solve {
    private static final int BOARD_SIZE = 10;
    private static final int PAPER_TYPES = 5;

    private int[] board = new int[BOARD_SIZE];
    private int[] papers = new int[PAPER_TYPES];
    private int ans = Integer.MAX_VALUE;

    public void getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Arrays.fill(papers, 5);

        IntStream.range(0, BOARD_SIZE)
                .forEach(i -> {
                    try {
                        int[] now = new int[1];
                        String[] split = br.readLine().split(" ");
                        IntStream.range(0, BOARD_SIZE)
                                .forEach(j -> {
                                    if (Integer.parseInt(split[j]) == 1) {
                                        now[0] |= (1 << j);
                                    }
                                });
                        board[i] = now[0];
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                });

        br.close();
    }

    private boolean isEmpty(int x, int y, int k) {
        return IntStream.rangeClosed(x, x + k)
                .allMatch(i -> IntStream.rangeClosed(y, y + k)
                        .allMatch(j -> (board[i] & (1 << j))>0));
    }

    private void toggle(int x, int y, int k) {
        IntStream.rangeClosed(x, x + k)
                .forEach(i -> IntStream.rangeClosed(y, y + k)
                        .forEach(j -> board[i] ^= (1 << j)));
    }

    private void dfs(int cnt, int x, int y) {
        if (x>=9 && y>9) {
            ans = Math.min(ans, cnt);
            return;
        }
        
        if(ans <= cnt)  return;
        
        if(y>9) {
            dfs(cnt, x+1, 0);
            return;
        }

        
            if ((board[x] & (1 << y)) > 0) {
                for (int k = 4; k >= 0; k--) {
                    if(x + k >9 || y+k>9)   continue;
                        if (isEmpty(x, y, k) && papers[k] > 0) {
                            toggle(x, y, k);
                            papers[k]--;
                            dfs(cnt+1, x, y);
                            papers[k]++;
                            toggle(x, y, k);
                        }
                    }
        }
        else {
            dfs(cnt, x, y+1);
        }
    }

    public void solve() throws IOException {
        getInput();

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        dfs(0, 0, 0);

        if(ans == Integer.MAX_VALUE)    bw.write("-1");
        else    bw.write(Integer.toString(ans));

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

