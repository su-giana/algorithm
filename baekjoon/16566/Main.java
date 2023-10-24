import java.io.*;
import java.util.*;

public class Main {
    static int n, m, k;
    static int[] selected = new int[4000000];
    static int[] displayed = new int[100000];
    static int[] set = new int[16000000];

    private static int isAvail(int val, int left, int right, int begin, int end)
    {
        if(right < begin || left > end) return -1;
        if(set[val] == 0)   return -1;
        if(left > right)    return -1;
        if(left == right)
        {
            set[val] = 0;
            return left;
        }

        int mid = left + (right - left) / 2;

        int leftSide = isAvail(2 * val, left, mid, begin, end);
        set[val] = set[val*2] + set[val*2+1];
        if(leftSide != -1)  return leftSide;
        else
        {
            int rightSide = isAvail(2*val+1, mid+1, right, begin, end);
            set[val] = set[val*2] + set[val*2+1];
            return rightSide;
        }
            
    }
    private static void initTree(int val, int left, int right)
    {
        if(left==right)
        {
            set[val] = 1;
            return;
        }
        
        int mid = left + (right - left) / 2;
        initTree(val*2, left, mid);
        initTree(val*2 + 1, mid+1, right);
        set[val] = set[val*2] + set[val*2 + 1];
    }
    private static int binSearch(int target)
    {
        int left = 0;
        int right = m-1;
        int indexOfGreater = -1;

        while(left<=right)
        {
            int mid = left + (right - left) / 2;

            if(selected[mid] > target)
            {
                indexOfGreater = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }

        if(indexOfGreater == -1)
        {
            return isAvail(1, 0, m-1, 0, m-1);
        }
        int tmp = isAvail(1, 0, m-1, indexOfGreater, m - 1);
        if(tmp == -1)   return isAvail(1, 0, m-1, 0, indexOfGreater-1);
        else            return tmp;
    }
    public static void getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer tokenizer = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tokenizer.nextToken());
        m = Integer.parseInt(tokenizer.nextToken());
        k = Integer.parseInt(tokenizer.nextToken());

        readArray(br.readLine(), selected, m);
        readArray(br.readLine(), displayed, k);

        br.close();
    }
    private static void readArray(String input, int[] arr, int length)
    {
        StringTokenizer tokenizer = new StringTokenizer(input);
        for (int i = 0; i < length; i++) {
            arr[i] = Integer.parseInt(tokenizer.nextToken());
        }
    }
    public static void solve() throws IOException
    {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Arrays.sort(selected, 0, m);
        initTree(1, 0, m-1);

        for(int i = 0 ; i<k ; i++)
        {
            int idx = binSearch(displayed[i]);
            bw.write(Integer.toString(selected[idx]) + "\n");
        }

        bw.flush();
        bw.close();
    }
    public static void main(String[] args) throws IOException {
        getInput();

        solve();
    }
}
