import java.util.*;
import java.io.*;

class Solve {
    int n;
    int[] nums;
    int[] lis; // Array to store the indices of the longest increasing subsequence
    int[] predecessors; // Array to store the predecessors' indices

    private void getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        nums = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        lis = new int[n];
        predecessors = new int[n];
        br.close();
    }

    public void solve() throws IOException {
        getInput();

        int length = 0; // Length of the current LIS
        Arrays.fill(predecessors, -1); // Initialize all predecessors to -1

        for (int i = 0; i < n; i++) {
            // Binary search
            int lo = 0, hi = length;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (nums[lis[mid]] < nums[i]) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }

            // Update LIS
            lis[lo] = i;
            if (lo > 0) {
                predecessors[i] = lis[lo - 1];
            }

            if (lo == length) {
                length++;
            }
        }

        // Reconstruct LIS
        int[] longestSubsequence = new int[length];
        for (int i = lis[length - 1], k = length - 1; k >= 0; i = predecessors[i], k--) {
            longestSubsequence[k] = nums[i];
        }

        // Output
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(length + "\n");
        for (int i = 0; i < length; i++) {
            bw.write(longestSubsequence[i] + " ");
        }
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