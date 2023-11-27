import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class Main {
    static int n, m, k;
    static PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> Integer.compare(b[2], a[2]));
    static int[] root = new int[10001];
    static List<List<int[]> > graph = new ArrayList<>();
    static boolean[] visited = new boolean[10001];
    static long[][] dp = new long[21][10001];

    static int find(int x)
    {
        if(root[x] == x)    return x;
        return root[x] = find(root[x]);
    }

    private static void getInput() throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] nmk = Arrays.stream(br.readLine().split(" "))
        .mapToInt(Integer::parseInt)
        .toArray();

        n = nmk[0];
        m = nmk[1];
        k = nmk[2];

        for(int i = 0 ; i<=n ; i++)
        {
            graph.add(new ArrayList<>());
        }

        for(int i = 0 ; i<m ; i++)
        {
            q.offer(Arrays.stream(br.readLine().split((" ")))
            .mapToInt(Integer::parseInt)
            .toArray());
        }

        for(int i = 0 ; i<=k ; i++)
        {
            for(int j = 0 ; j<=n ; j++)
            {
                dp[i][j] = -1;
            }
        }

        br.close();
    }

    private static long dfs(int cur, int cnt, long sumOfWeight)
    {
        if(dp[cnt][cur] != -1 && dp[cnt][cur] <= sumOfWeight)   return Long.MAX_VALUE;
        
        if(cur == n)
        {
            return sumOfWeight;
        }

        long ans = Long.MAX_VALUE;
        int g_size = graph.get(cur).size();
        for(int i = 0 ; i<g_size ; i++)
        {
            int next = graph.get(cur).get(i)[0];
            int cost = graph.get(cur).get(i)[1];

            if(!visited[next])
            {
                visited[next] = true;
                ans = Long.min(ans, dfs(next, cnt, sumOfWeight + cost));
                if(cnt>0)
                {
                    ans = Long.min(ans, dfs(next, cnt-1, sumOfWeight));
                }
                visited[next] = false;
            }
        }

        dp[cnt][cur] = ans;
        return ans;
    }
    
    private static void solve() throws IOException
    {
        for(int i = 1 ; i<=n ; i++)  root[i] = i;

        while(!q.isEmpty())
        {
            int[] cur = q.poll();
            int dep = cur[0];
            int des = cur[1];
            int cost = cur[2];

            if(find(dep) == find(des))  continue;

            root[find(des)] = find(dep);    
            graph.get(dep).add(new int[]{des, cost});
            graph.get(des).add(new int[]{dep, cost});
        }

        visited[1] = true;
        long ans = dfs(1, k, 0);
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Long.toString(ans));
        bw.flush();
        bw.close();
    }

    public static void main(String[] args) throws IOException {
        getInput();
        solve();
    }   
}
