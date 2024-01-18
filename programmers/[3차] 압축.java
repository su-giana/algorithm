import java.util.*;
import java.io.*;

class Solution {
    Map<String, Integer> hm = new HashMap<>( );
    List<Integer> ans = new ArrayList<>( );
    
    public int[] solution(String msg) {
        String cur = "";
        int idx = 0; // next index of dictionary
        int nxt = 0; // next char index at msg
        
        hm.put("", idx++);
        for (char c = 'A' ; c <= 'Z' ; c++) {
            hm.put("" + c, idx++);
        }
        
        while (nxt < msg.length( )) {
            String tmp = "";
            while (nxt < msg.length( )) {
                tmp += msg.charAt(nxt);
                
                if (!hm.containsKey(tmp)) {
                    break;
                }
               	nxt++;
                cur = tmp;
            }
            
            ans.add(hm.get(cur));
            if (nxt >= msg.length( ))	break;
            
            hm.put(tmp, idx);
            idx++;
        }
        
        
        return ans.stream( )
            .mapToInt(Integer::intValue)
            .toArray( );
    }
}