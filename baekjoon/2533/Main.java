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
    public static void main(String[] args) throws IOException {
        new Solve().solve();
    }
}

class Node {
    public int val;
    public int isEarlyAdapter;
    public List<Node> children;

    public Node(int val) {
        this.val = val;
        this.isEarlyAdapter = 0;
        this.children = new ArrayList<>();
    }

    public int countNotEarlyAdapter( ) {
        return children.stream()
        .mapToInt(node -> node.isEarlyAdapter)
        .sum();
    }
}

class Solve {
    List<Node> nodes = new ArrayList<>();
    int n;

    public void getInput( ) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        this.n = Integer.parseInt(br.readLine());

        for(int i = 0 ; i<=n ; i++) {
            this.nodes.add(new Node(i));
        }

        for(int i = 1 ; i<n ; i++) {
            int[] split = Arrays.asList(br.readLine().split(" ")).stream()
            .mapToInt(Integer::parseInt)
            .toArray();

            int u = split[0];
            int v = split[1];

            nodes.get(u).children.add(nodes.get(v));
            nodes.get(u).isEarlyAdapter++;
            nodes.get(v).children.add(nodes.get(u));
            nodes.get(v).isEarlyAdapter++;
        }

        br.close();
    }

    public int calculate( ) {
        
        PriorityQueue<Node> q = new PriorityQueue<>((node1, node2) -> node2.isEarlyAdapter - node1.isEarlyAdapter);
        for(int i = 1 ; i<=n ; i++) {
            q.offer(this.nodes.get(i));
        }

        int ans = 0;

        while(!q.isEmpty() && q.peek( ).isEarlyAdapter > 0) {
            Node now = q.poll();
            for(Node node : now.children) {
                System.out.println(node.val);
                node.isEarlyAdapter--;
            }
            System.out.println();
            ans++;
        }

        return ans;
    }

    public void solve() throws IOException{
        getInput();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Integer.toString(calculate()));
        bw.flush();
        bw.close();
    }
}