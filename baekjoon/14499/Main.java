import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main
{
    static Deque<Integer> horizonDice = new ArrayDeque<>(Arrays.asList(0, 0, 0, 0));
    static Deque<Integer> verticalDice = new ArrayDeque<>(Arrays.asList(0, 0, 0, 0));
    static int n, m, x, y, k;
    static int[][] map = new int[20][20];
    static int[] actions = new int[1000];
    static int[] dx = {0, 0, -1, 1};
    static int[] dy = {1, -1, 0, 0};

    private static void getInput() throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line);
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for(int i = 0 ; i<n ; i++)
        {
            String pos = br.readLine();
            String[] nums = pos.split(" ");
            for(int j = 0 ; j<m ; j++)
            {
                map[i][j] = Integer.parseInt(nums[j]);
            }
        }

        String action = br.readLine();
        String[] actionString = action.split(" ");
        for(int i = 0 ; i<k ; i++)
        {
            actions[i] = Integer.parseInt(actionString[i]);
        }

        br.close();
    }

    private static void moveDice(int dir)
    {
        if(dir < 2)
        {
            if(dir == 0)
            {
                horizonDice.addFirst(horizonDice.getLast());
                horizonDice.removeLast();
            }
            if(dir == 1)
            {
                horizonDice.addLast(horizonDice.getFirst());
                horizonDice.removeFirst();
            }

            Integer[] horizonArray = horizonDice.toArray(new Integer[0]);
            Integer[] verticalArray = verticalDice.toArray(new Integer[0]);

            if(map[x][y] == 0)
            {
                map[x][y] = horizonArray[2];
            }
            else
            {
                horizonArray[2] = map[x][y];
                map[x][y] = 0;
            }

            verticalArray[0] = horizonArray[0];
            verticalArray[2] = horizonArray[2];

            horizonDice = new ArrayDeque<>(Arrays.asList(horizonArray));
            verticalDice = new ArrayDeque<>(Arrays.asList(verticalArray));
        }
        else
        {
            if(dir == 2)
            {
                verticalDice.addFirst(verticalDice.getLast());
                verticalDice.removeLast();
            }
            if(dir == 3)
            {
                verticalDice.addLast(verticalDice.getFirst());
                verticalDice.removeFirst();
            }

            Integer[] horizonArray = horizonDice.toArray(new Integer[0]);
            Integer[] verticalArray = verticalDice.toArray(new Integer[0]);

            if(map[x][y] == 0)
            {
                map[x][y] = verticalArray[2];
            }
            else
            {
                verticalArray[2] = map[x][y];
                map[x][y] = 0;
            }

            horizonArray[0] = verticalArray[0];
            horizonArray[2] = verticalArray[2];

            horizonDice = new ArrayDeque<>(Arrays.asList(horizonArray));
            verticalDice = new ArrayDeque<>(Arrays.asList(verticalArray));
        }
    }

    private static void solve() throws IOException
    {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter((System.out)));
        for(int i = 0 ; i<k ; i++)
        {
            int dir = actions[i]-1;
            int tx = x + dx[dir];
            int ty = y + dy[dir];

            if(tx<0 || ty<0 || tx>=n || ty>=m)
            {
                continue;
            }

            x = tx; y = ty;

            moveDice(dir);
            bw.write(Integer.toString(horizonDice.getFirst()) + '\n');
        }        
        bw.flush();
        bw.close();
    }

    public static void main(String[] args) throws IOException
    {
        getInput();

        solve();
    }
}