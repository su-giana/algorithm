import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;

class Node {
    String name;
    List<Node> subNodes;

    public Node(String name) {
        this.name = name;
    }
}

class Solve {
    int n;
    Node entrancNode = new Node("개미굴 입구");

    public void solve( ) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        this.n = Integer.parseInt(br.readLine());

        
    }
}

public class Main {
    
}
