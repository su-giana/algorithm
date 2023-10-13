#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

int n;
vector<int> inOrder;
vector<int> postOrder;

struct Node
{
    int val;
    Node* left;
    Node* right;
    
    Node(int val_)
    {
        val = val_;
        left = NULL;
        right = NULL;
    }
};

void printTree(Node* node)
{
    if(node == NULL)    return;

    cout<<node->val<<' ';
    printTree(node->left);
    printTree(node->right);
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

Node* makeTree(pii inOrd, pii postOrd)
{
    int inL = inOrd.first;
    int inR = inOrd.second;
    int postL = postOrd.first;
    int postR = postOrd.second;

    if(inOrd.first > inOrd.second)    return NULL;
    if(inOrd.first == inOrd.second)
    {
        return new Node(postOrder[postR]);
    }

    int root = postOrder[postR];

    int inOrderRootIdx = find(inOrder.begin() + inL, inOrder.begin() + inR + 1, root) - inOrder.begin();

    int gap = inOrderRootIdx - inL - 1;

    Node* node = new Node(root);
    node->left = makeTree(make_pair(inL, inOrderRootIdx - 1), make_pair(postL, postL + gap));
    node->right = makeTree(make_pair(inOrderRootIdx + 1, inR), make_pair(postL + gap + 1, postR-1));

    return node;
}

int main()
{
    init();

    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        int num;
        cin>>num;
        inOrder.push_back(num);
    }

    for(int i = 0 ; i<n ; i++)
    {
        int num;
        cin>>num;
        postOrder.push_back(num);
    };

    Node* tree = makeTree(make_pair(0, n-1), make_pair(0, n-1));
    printTree(tree);
}