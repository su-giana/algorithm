import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.Map;
import java.util.StringTokenizer;

public class Main
{
    static long[] nums = new long[1000000];
    static int n;
    static ArrayList<Map.Entry<Integer, Long> > ans = new ArrayList<>();
    static int[] root = new int[1000000];

    public static void getInput() throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        String input = br.readLine();
        StringTokenizer tokenizer = new StringTokenizer(input);

        for(int i = 0 ; i<n ; i++)
        {
            String token = tokenizer.nextToken();
            int num = Integer.parseInt(token);
            nums[i] = num;
        }
        
        br.close();
    }

    public static int binSearch(long target)
    {
        int left = 0;
        int right = ans.size() - 1;
        int closestGreaterTarget = -1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(ans.get(mid).getValue() >= target)
            {
                closestGreaterTarget = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return closestGreaterTarget;
    }

    public static void solve() throws IOException
    {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for(int i = 0 ; i<n ; i++)  root[i] = i;

        Map.Entry<Integer, Long> initMap = new AbstractMap.SimpleEntry<>(0, nums[0]);
        ans.add(initMap);

        for(int i = 1 ; i<n ; i++)
        {
            long cur = nums[i];
            Map.Entry<Integer, Long> last = ans.get(ans.size()-1);

            if(cur > last.getValue())
            {
                Map.Entry<Integer, Long> newPair = new AbstractMap.SimpleEntry<>(i, nums[i]);
                ans.add(newPair);
                
                root[i] = last.getKey();
            }
            if(cur < last.getValue())
            {
                Map.Entry<Integer, Long> replacePair = new AbstractMap.SimpleEntry<>(i, nums[i]);
                int idx = binSearch(cur);
                ans.set(idx, replacePair);

                if(idx > 0)
                {
                    Map.Entry<Integer, Long> prevPair = ans.get(idx-1);
                    root[i] = prevPair.getKey();
                }
            }
        }

        int cur = ans.get(ans.size() - 1).getKey();
        ArrayList<Long> answer = new ArrayList<>();
        answer.add(nums[cur]);

        while(cur != root[cur])
        {
            cur = root[cur];
            answer.add(nums[cur]);
        }

        bw.write(Integer.toString(ans.size()));
        bw.write("\n");

        for(int i = ans.size()-1 ; i>=0 ; i--)
        {
            bw.write(Long.toString(answer.get(i)));
            bw.write("\n");
        }
        
        bw.flush();
        bw.close();
    }

    public static void main(String[] args) throws IOException{
        getInput();
        solve();
    }
}