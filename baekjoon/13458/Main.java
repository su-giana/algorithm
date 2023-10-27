import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main
{
    static int n, b, c;
    static int[] rooms = new int[1000000];

    public static void solve() throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        String a = br.readLine();
        StringTokenizer tokenizer = new StringTokenizer(a);

        for(int i = 0 ; i<n ; i++)
        {
            rooms[i] = Integer.parseInt(tokenizer.nextToken());
        }

        String bc = br.readLine();
        tokenizer = new StringTokenizer(bc);

        b = Integer.parseInt(tokenizer.nextToken());
        c = Integer.parseInt(tokenizer.nextToken());

        long ans = 0;
        for(int i = 0 ; i<n ; i++)
        {
            if(rooms[i] <= b)   { ans++; continue; }
            rooms[i] -= b;
            ans += (rooms[i] / c) + 1;
            if(rooms[i]%c > 0)
            {
                ans += 1;
            }
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Long.toString(ans));

        bw.flush();
        bw.close();
        br.close();
    }

    public static void main(String[] args) throws IOException{
        solve();
    }
}