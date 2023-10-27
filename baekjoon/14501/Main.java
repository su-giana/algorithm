import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.AbstractMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static Map.Entry<Integer, Integer>[] schedules = new AbstractMap.SimpleEntry[1000];

    public static void getInput() throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        for(int i = 0 ; i<n ; i++)
        {
            String schedule = br.readLine();
            StringTokenizer scTokenizer = new StringTokenizer(schedule);
            int day = Integer.parseInt(scTokenizer.nextToken());
            int gain = Integer.parseInt(scTokenizer.nextToken());
            schedules[i] = new AbstractMap.SimpleEntry<>(day, gain);
        }
    
        br.close();
    }

    public static int dfs(int day, int cost)
    {
        if(day>n)  return -1;
        if(day == n)    return cost;

        Map.Entry<Integer, Integer> schedule = schedules[day];

        return Math.max(dfs(day+1, cost), dfs(day+schedule.getKey(), cost + schedule.getValue()));
    }

    public static void solve() throws IOException
    {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int maximumGain = dfs(0, 0);
        bw.write(Integer.toString(maximumGain));
        bw.flush();
        bw.close();
    }

    public static void main(String[] args) throws IOException {
        getInput();

        solve();
    }
}
