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
            board[x-1][y-1] = 1;
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
        if(turn == 'D')
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
        Queue<int[]> q = new ArrayDeque<>();
        int[] curPos = {0, 0};
        q.offer(curPos);
        board[0][0] = 2;

        int curDir = 0, ans = 0, actionPos = 0;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while(true)
        {
            if(actionPos < l)
            {
                Map.Entry<Integer, Character> action = actions[actionPos];
                int mSize = action.getKey();
                char turn = action.getValue();
                if(ans == mSize)
                {
                    curDir = getDir(curDir, turn);
                    actionPos++;
                }
            }
            
            int tx = curPos[0] + dx[curDir];
            int ty = curPos[1] + dy[curDir];

            if(tx<0||ty<0||tx>=n||ty>=n)    return ans+1;
            if(board[tx][ty] == 2)          return ans+1;
            
            if(board[tx][ty] == 0)
            {
                int[] tail = q.poll();
                board[tail[0]][tail[1]] = 0;
            }

            board[tx][ty] = 2;
            curPos = new int[]{tx, ty};
            q.offer(curPos);
                
            ans++;
        }
    }

    public static void main(String[] args) throws IOException{
        getInput();

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(Integer.toString(solve()));
        bw.flush();
        bw.close();
    }
    
}
