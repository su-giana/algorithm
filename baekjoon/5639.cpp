#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
public:
    int val;
    TreeNode* leftNode;
    TreeNode* rightNode;

    
    TreeNode(int val_)
    {
        val = val_;
        leftNode = NULL;
        rightNode = NULL;
    }
};

TreeNode* root = NULL;
int val;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void dfs(TreeNode* cur)
{
    if(cur == NULL)
    {
        root = new TreeNode(val);
        return;
    }

    if(val < cur->val)
    {
        if(cur->leftNode == NULL)
        {
            cur->leftNode =  new TreeNode(val);
        }
        else
        {
            dfs(cur->leftNode);
        }
    }
    else
    {
        if(cur->rightNode == NULL)
        {
            cur->rightNode = new TreeNode(val);
        }
        else
        {
            dfs(cur->rightNode);
        }
    }
}

void postorderTraversal(TreeNode* cur)
{
    if(cur->leftNode != NULL)   postorderTraversal(cur->leftNode);
    if(cur->rightNode != NULL)  postorderTraversal(cur->rightNode);
    cout<<cur->val<<'\n';
    return;
}

int main()
{

    while(cin>>val)
    {
        dfs(root);
        if(cin.eof() == true)   break;
    }

    if(root == NULL)    return 0;

    postorderTraversal(root);

}