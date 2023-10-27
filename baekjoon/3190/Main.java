import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.AbstractMap;
import java.util.ArrayDeque;
import java.util.Map;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n, k, l;
    static Map.Entry<Integer, Integer>[] apples = new AbstractMap.SimpleEntry[100];
    static Map.Entry<Integer, Character>[] actions = new AbstractMap.SimpleEntry[100];
    static int[][] board = new int[100][100];

    private static void getInput() throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());

        for(int i = 0 ; i< k ; i++)
        {
            String apple = br.readLine();
            StringTokenizer appleTokenizer = new StringTokenizer(apple);
            int x = Integer.parseInt(appleTokenizer.nextToken());
            int y = Integer.parseInt(appleTokenizer.nextToken());
            board[x][y] = 1;
            apples[i] = new AbstractMap.SimpleEntry<>(x, y);
        }

        l = Integer.parseInt(br.readLine());

        for(int i = 0 ; i<l ; i++)
        {
            String action = br.readLine();
            StringTokenizer acTokenizer = new StringTokenizer(action);
            int move = Integer.parseInt(acTokenizer.nextToken());
            char dir = acTokenizer.nextToken().charAt(0);
            actions[i] = new AbstractMap.SimpleEntry<>(move, dir);
        }

        br.close();
    }

    private static int getDir(int curDir, char turn)
    {
        if(turn == 'L')
        {
            curDir += 1;
            curDir = curDir % 4;
        }
        else
        {
            curDir  -= 1;
            if(curDir < 0)
            {
                curDir = 3;
            }
        }
        
        return curDir;
    }

    private static int solve()
    {
        Queue<Map.Entry<Integer, Integer> > q = new ArrayDeque<>();
        Map.Entry<Integer, Integer> curPos = new AbstractMap.SimpleEntry<>(0, 0);
        q.offer(new AbstractMap.SimpleEntry<>(0, 0));
        board[0][0] = 2;

        int curDir = 0, ans = 0;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i = 0 ; i<l ; i++)
        {
            Map.Entry<Integer, Character> action = actions[i];
            int cx = curPos.getKey();
            int cy = curPos.getValue();
            int mSize = action.getKey();
            char turn = action.getValue();

            curDir = getDir(curDir, turn);
            for(int j = 0 ; j<mSize ; j++)
            {
                int tx = cx + dx[curDir];
                int ty = cy + dy[curDir];

                if(tx<0||ty<0||tx>=n||ty>=n)    return ans;
                if(board[tx][ty] == 2)          return ans;
                else if(board[tx][ty] == 1)
                {
                    board[tx][ty] = 2;
                    curPos = new AbstractMap.SimpleEntry<>(tx, ty);
                    q.offer(curPos);
                }
                else
                {
                    board[tx][ty] = 2;
                    curPos = new AbstractMap.SimpleEntry<>(tx, ty);
                    q.offer(curPos);
                    
                    Map.Entry<Integer, Integer> tail = q.poll();
                    board[tail.getKey()][tail.getValue()] = 0;
                }
                ans++;
            }
        }
        
        return ans;
    }

    public static void main(String[] args) throws IOException{
        getInput();

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(Integer.toString(solve()));
        bw.flush();
        bw.close();
    }
    
}
