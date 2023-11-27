import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

import javax.swing.border.MatteBorder;

public class Main
{
    static int k, c;
    static int[] cutPos = new int[10000];
    static long l;

    public static void getInput() throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String lkc = br.readLine();
        String[] lkcArray = lkc.split(" ");
        l = Long.parseLong(lkcArray[0]);
        k = Integer.parseInt(lkcArray[1]);
        c = Integer.parseInt(lkcArray[2]);
        
        String curPosString = br.readLine();
        String[] cutPosStringArray = curPosString.split(" ");
        for(int i = 0 ; i<k ; i++)
        {
            cutPos[i] = Integer.parseInt(cutPosStringArray[i]);
        }

        br.close();
    }

    public static int binarySearch(long target)
    {
        int left = 0;
        int right = k-1;
        int greaterThanThis = -1;
        
        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(cutPos[mid] >= target)
            {
                right = mid - 1;
                greaterThanThis = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return greaterThanThis;
    }

    public static long trologySearch(long begin, long end)
    {
        int left = 0;
        int right = k-1;
        int cnt = 0;

        if(end - begin == 0)    return -1;
        int curPos = binarySearch(begin);

        if(curPos == -1)    return -1;

        long shortAns = Integer.MAX_VALUE;
        int ansPos = -1;
        for(int i = 0 ; end - begin <= 2 && i<end - begin ; i++)
        {
            if(curPos + i >= cutPos.length) break;

            long cur = cutPos[curPos + i];
            long next = Math.max(cur - begin, end - cur);
            if(cur >= begin && cur <= end && shortAns > next)
            {
                shortAns = next;
                ansPos = curPos + i;
            }
        }
        if(begin == 3 && end == 5)  System.out.println(ansPos);
        if(end - begin <= 2) return cutPos[ansPos];

        while(cnt++ <= 3000)
        {
            if(left < 0 || right >= k)  return -1;

            int leftSide = (2*left + right) / 3;
            int rightSide = (left + 2*right) / 3;

            long leftLeftSide = cutPos[leftSide] - begin;
            long leftRightSide = end - cutPos[rightSide];
            long rightLeftSide = cutPos[rightSide] - begin;
            long rightRightSide = end - cutPos[rightSide];
            long leftValue = Math.min(leftLeftSide, leftRightSide);
            long rightValue = Math.min(rightLeftSide, rightRightSide);

            if(leftValue < 0)
            {
                left = leftSide + 1;
                continue;
            }
            if(rightValue < 0)
            {
                right = rightSide - 1;
                continue;
            }

            if(rightValue > leftValue)
            {
                left = leftSide;
            }
            else if(leftValue > rightValue)
            {
                right = rightSide;
            }
            else
            {
                return cutPos[leftSide];
            }
        }

        shortAns = Integer.MAX_VALUE;
        long ans = -1;
        for(long i = left ; i<=right ; i++)
        {
            long next = Math.max(i - begin, end - i);
            if(i >= begin && i <= end && shortAns > next)
            {
                shortAns = next;
                ans = i;
            }
        }

        return ans;
    }

    public static void solve() throws IOException
    {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        PriorityQueue<long[]> q = new PriorityQueue<>(new Comparator<long[]>() 
        {
            @Override
            public int compare(long[] o1, long[] o2)
            {
                if(o1[1] - o1[0] == o2[1] - o2[0])  return Long.compare(o1[0], o2[0]);
                return Long.compare(Math.abs(o2[1] - o2[0]), Math.abs(o1[1] - o1[0]));
            }
        });

        Arrays.sort(cutPos, 0, k);

        List<Long> ans = new ArrayList<>();
        q.offer(new long[]{0, l});
        for(int i = 0 ; i<c ; i++)
        {
            long[] cur = q.poll();
            long idx = trologySearch(cur[0], cur[1]);

            if(idx == -1)
            {
                q.offer(cur);
                break;
            }

            ans.add(idx);
            if(idx == cur[0])
            {
                q.offer(new long[]{cur[0], idx});
                q.offer(new long[]{idx+1, cur[1]});
            }
            else if(idx == cur[1])
            {
                q.offer(new long[]{cur[0], idx-1});
                q.offer(new long[]{idx, cur[1]});
            }
            else
            {
                q.offer(new long[]{cur[0], idx});
                q.offer(new long[]{idx+1, cur[1]});
            }
        }

        ans.sort(null);
        long[] cur = q.poll();
        bw.write(Long.toString(cur[1] - cur[0]) + " ");
        bw.write(Long.toString(ans.get(0)));
        bw.flush();
        bw.close();
    }
    
    public static void main(String[] args) throws IOException {
        getInput();

        solve();
    }
}