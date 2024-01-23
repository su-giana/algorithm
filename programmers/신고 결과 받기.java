import java.util.*;
import java.io.*;

class Solution {
    Map<String, Integer> mp = new HashMap<>( );
    public int[] solution(String[] id_list, String[] report, int k) {
        int idx = 0;
        
        for (String id : id_list) {
            mp.put(id, idx++);
        }
        
        int[][] mem = new int[1000][1000];
        
        for (String rep : report) {
            String reporter = rep.split(" ")[0];
            String reportee = rep.split(" ")[1];
            
            mem[mp.get(reporter)][mp.get(reportee)] = 1;
        }
        
        int[] result = new int[1000];
        
        for (int i = 0 ; i<1000 ; i++) {
            for (int j = 0 ; j<1000 ; j++) {
                result[i] += mem[j][i];
            }
        }
        
        int[] answer = new int[idx];
        for (int i = 0 ; i<idx ; i++) {
            for (int j = 0 ; j<idx ; j++) {
                if (mem[i][j] > 0 && result[j] >= k) {
                    answer[i]++;
                }
            }
        }
        
        return answer;
    }
}