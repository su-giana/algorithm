import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class Solve {
    private static final int BOARD_SIZE = 10;
    private static final int PAPER_TYPES = 4;

    private int[] board = new int[BOARD_SIZE];
    private int[] papers = new int[PAPER_TYPES];
    private Map<List<Integer>, List<Integer>> map = new HashMap<>();

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

    private boolean isEffective(int[] bd, int[] pap) {
        List<Integer> keyList = Arrays.stream(bd).boxed().collect(Collectors.toList());
        return !map.containsKey(keyList) || Arrays.stream(map.get(keyList).stream().mapToInt(i -> 5 - i).toArray()).sum() > Arrays.stream(pap).sum();
    }

    private boolean isEmpty(int[] bd, int x, int y, int k) {
        return IntStream.rangeClosed(x, x + k)
                .allMatch(i -> IntStream.rangeClosed(y, y + k)
                        .allMatch(j -> (bd[i] & (1 << j)) == 0));
    }

    private void toggle(int[] bd, int x, int y, int k) {
        IntStream.rangeClosed(x, x + k)
                .forEach(i -> IntStream.rangeClosed(y, y + k)
                        .forEach(j -> bd[i] ^= (1 << j)));
    }

    private void dfs(int[] bd, int[] pap) {
        if (Arrays.stream(bd).sum() == 0) {
            int now = Arrays.stream(pap).map(i -> 5 - i).sum();
            List<Integer> keyList = Arrays.stream(bd).boxed().collect(Collectors.toList());
            if (!map.containsKey(keyList) || now < Arrays.stream(map.get(keyList).stream().mapToInt(Integer::intValue).toArray()).sum()) {
                map.put(keyList, Arrays.stream(pap).map(i -> 5 - i).boxed().collect(Collectors.toList()));
            }
            return;
        }

        if (!isEffective(bd, pap)) {
            return;
        }

        List<Integer> keyList = Arrays.stream(bd).boxed().collect(Collectors.toList());
        map.put(keyList, Arrays.stream(pap).map(i -> 5 - i).boxed().collect(Collectors.toList()));

        for (int k = 0; k < 5; k++) {
            for (int i = 0; i < BOARD_SIZE - k; i++) {
                for (int j = 0; j < BOARD_SIZE - k; j++) {
                    if ((bd[i] & (1 << j)) > 0) {
                        if (isEmpty(bd, i, j, k) && pap[k] > 0) {
                            toggle(bd, i, j, k);
                            pap[k]--;
                            dfs(bd, pap);
                            pap[k]++;
                            toggle(bd, i, j, k);
                        }
                    }
                }
            }
        }
    }

    public void solve() throws IOException {
        getInput();

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        dfs(board, papers);

        List<Integer> zeroArrayKey = Arrays.stream(new int[BOARD_SIZE]).boxed().collect(Collectors.toList());
        if (map.containsKey(zeroArrayKey)) {
            bw.write(Integer.toString(Arrays.stream(map.get(zeroArrayKey).stream().mapToInt(Integer::intValue).toArray()).sum()));
        } else {
            bw.write(Integer.toString(-1));
        }

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
