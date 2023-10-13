#include <iostream>
#include <vector>
#include <algorithm>

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

Node* makeTree(int left, int right)
{
    if(left > right)    return NULL;
    if(left == right)
    {
        return new Node(postOrder[right]);
    }

    int root = postOrder[right];

    int inOrderRootIdx = find(inOrder.begin() + left, inOrder.begin() + right + 1, root) - inOrder.begin();

    Node* node = new Node(root);
    node->left = makeTree(left, inOrderRootIdx - 1);
    node->right = makeTree(inOrderRootIdx + 1, right);

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

    printTree(makeTree(0, n-1));
}