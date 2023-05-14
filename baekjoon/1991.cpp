#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    public:
    char name;
    Node *leftNode = NULL;
    Node *rightNode = NULL;

    Node(char c, Node* lNode, Node* rNode)
    {
        name = c;
        leftNode = lNode;
        rightNode = rNode;
    }
};

void preTraversal(Node* root)
{
    if(root == NULL)    return;

    cout<<root->name;
    preTraversal(root->leftNode);
    preTraversal(root->rightNode);
}

void inTraversal(Node* root)
{
    if(root==NULL)  return;

    inTraversal(root->leftNode);
    cout<<root->name;
    inTraversal(root->rightNode);
}

void postTraversal(Node* root)
{
    if(root==NULL)  return;

    postTraversal(root->leftNode);
    postTraversal(root->rightNode);
    cout<<root->name;
}

int main()
{
    int n;
    cin>>n;

    vector<Node*> nodes;
    for(int i = 0 ; i<n ; i++)
    {
        
        Node *temp = new Node('A' + i, NULL, NULL);
        nodes.push_back(temp);
    }

    for(int i = 0 ; i<n ; i++)
    {
        char root, left, right;
        cin>>root>>left>>right;

        if(left != '.')   nodes[root - 'A']->leftNode = nodes[left - 'A'];
        if(right != '.')  nodes[root - 'A']->rightNode = nodes[right-'A'];
    }

    preTraversal(nodes[0]);
    cout<<endl;
    inTraversal(nodes[0]);
    cout<<endl;
    postTraversal(nodes[0]);
}