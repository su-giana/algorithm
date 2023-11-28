import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.List;

class Solve {
    int n, l;
    int[][] board = new int[100][100];
    boolean[][][] visited = new boolean[100][100][2];

    private void getInput( ) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nl = br.readLine().split(" ");
        n = Integer.parseInt(nl[0]);
        l = Integer.parseInt(nl[1]);

        for(int i = 0 ; i <n ; i++) {
            board[i] = Arrays.stream(br.readLine().split(" "))
                        .mapToInt(Integer::parseInt)
                        .toArray();
        }
        br.close();
    }

    private boolean isAllSameLower(int path, int idx, boolean isRow) {
        if(idx + l >= n)    return false;

        for(int i = idx + 1 - l ; i<=idx ; i++) {
            if(isRow) {
                if(visited[path][i][0]) {
                    return false;
                }
            }
            else {
                if(visited[i][path][1]) {
                    return false;
                }
            }
        }

        for(int i = idx + 1 - l ; i< idx ; i++) {
            if(isRow && (board[path][i] != board[path][i+1]))   return false;
            if(!isRow && (board[i][path] != board[i+1][path]))   return false;
        }

        for(int i = idx + 1 - l ; i<=idx ; i++) {
            if(isRow) {
                visited[path][i][0] = true;
            }
            else {
                visited[i][path][1] = true;
            }
        }

        return true;
    }

    private boolean isAllSameUpper(int path, int idx, boolean isRow) {
        if(idx + l >= n)    return false;

        for(int i = idx + 1 ; i<=idx+l ; i++) {
            if(isRow) {
                if(visited[path][i][0]) {
                    return false;
                }
            }
            else {
                if(visited[i][path][1]) {
                    return false;
                }
            }
        }

        for(int i = idx + 1 ; i< idx + l ; i++) {
            if(isRow && (board[path][i] != board[path][i+1]))   return false;
            if(!isRow && (board[i][path] != board[i+1][path]))   return false;
        }

        for(int i = idx + 1 ; i<=idx+l ; i++) {
            if(isRow) {
                visited[path][i][0] = true;
            }
            else {
                visited[i][path][1] = true;
            }
        }

        return true;
    }

    private boolean checkPath(int path, int idx, boolean isRow) {
        if(idx == n-1)  return true;

        int diff;
        if(isRow)   diff = Math.abs(board[path][idx] - board[path][idx+1]);
        else        diff = Math.abs(board[idx][path] - board[idx+1][path]);
        if(diff == 1) {
            if(!isAllSame(path, idx, isRow))    return false;
            return checkPath(path, idx + l, isRow);
        }
        else if(diff > 1)   return false;
        return checkPath(path, idx+1, isRow);
    }

    public void solve( ) throws IOException {
        getInput();
        int cnt = 0;

        for(int i = 0 ; i < n ; i++) {
            if(checkPath(i, 0, true))   cnt++;
            if(checkPath(i, 0, false))  cnt++;
        }

        BufferedWriter bw  = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Integer.toString(cnt));
        bw.flush();
        bw.close();
    }
}


public class Main {
    public static void main(String[] args) throws IOException {
        Solve solve = new Solve();
        solve.solve();
    }
}