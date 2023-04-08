#include <iostream>
#include <vector>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    vector<Node*> nodes = vector<Node*>(101, NULL);
    bool inList(Node* node, vector<Node*> nodes)
    {
        for(int i = 0 ; i<nodes.size() ; i++)
        {
            if(nodes[i] == node)    return true;
        }
        return false;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)    return NULL;

        if(nodes[node->val] != NULL)    return node;

        Node* newNode = new Node(node->val);
        nodes[node->val] = newNode;

        if(node->neighbors.empty()) return newNode;

        for(int i = 0 ; i<node->neighbors.size() ; i++)
        {
            if(nodes[node->neighbors[i]->val] != NULL)
            {
                Node* neighbor = nodes[node->neighbors[i]->val];
                if(!inList(neighbor, newNode->neighbors))
                    newNode->neighbors.push_back(neighbor);
                if(!inList(newNode, neighbor->neighbors))
                    neighbor->neighbors.push_back(newNode);
            }
            else    cloneGraph(node->neighbors[i]);
        }


        return newNode;
    }
};