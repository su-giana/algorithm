import java.io.*;
import java.util.*;

public class Node {
        public long val;
        Node next;
        
        public Node(long val) {
            this.val = val;
            this.next = null;
        }
        
        public Node(long val, Node next) {
            this.val = val;
            this.next = next;
        }
    }

class Solution {
    private Node findNode(Node cur) {
        if (cur.next == null) {
            return cur;
        }
        return cur.next = findNode(cur.next);
    }
    
    public long[] solution(long k, long[] room_number) {
        Map<Long, Node> table = new HashMap<>( );
        List<Long> ans = new ArrayList<> ( );
        
        for (long room : room_number) {
            long assigned = -1;
            Node next = null;
            Node cur = null;
            
            if (table.containsKey(room)) {
                Node last = findNode(table.get(room));
                assigned = last.val + 1;
            }
            else {
                assigned = room;
            }
            
            if (table.containsKey(assigned + 1))	next = table.get(assigned + 1);
            cur = new Node(assigned, next);
            table.put(assigned, cur);
            
            if (table.containsKey(assigned - 1))	table.get(assigned - 1).next = cur;
            ans.add(assigned);
        }
        
        return ans.stream( )
            .mapToLong(Long::longValue)
            .toArray( );
    }
}