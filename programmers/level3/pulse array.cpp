#include <string>
#include <vector>

using namespace std;

struct TreeNode
{
    long long left;
    long long right;
    long long maxArr;
    long long sum;
    
    TreeNode(){}

    void changeTo(long long left_, long long right_, long long maxArr_, long long sum_)
    {
        left = left_;
        right = right_;
        maxArr = maxArr_;
        sum = sum_;
    }
};

vector<TreeNode*> tree;
vector<int> arr;

void initTree(int node, int begin, int end)
{
    TreeNode* cur = tree[node];
    if(begin==end)
    {
        int leaf = arr[begin];
        cur->changeTo(leaf, leaf, leaf, leaf);
        return;
    }
    
    int mid = begin + (end-begin)/2;
    initTree(2*node, begin, mid);
    initTree(2*node+1, mid+1, end);
    
    TreeNode* left = tree[2*node];
    TreeNode* right = tree[2*node+1];
    cur->left = max(left->left, left->sum + right->left);
    cur->right = max(left->right + right->sum, right->right);
    cur->maxArr = max(max(left->maxArr, right->maxArr), left->right + right->left);
    cur->sum = left->sum + right->sum;
}

long long solution(vector<int> sequence) {
	int n = sequence.size();
    
    for(int i = 0 ; i<4*n ; i++)
    {
        TreeNode* node = new TreeNode;
        tree.push_back(node);
    }
    
    vector<int> sequenceOdd(sequence.begin(), sequence.end());
    vector<int> sequenceEven(sequence.begin(), sequence.end());
    for(int i = 0 ; i<n ; i++)
    {
        if(i%2==0)
        {
            sequenceEven[i] *= -1;
        }
        else
        {
            sequenceOdd[i] *= -1;
        }
    }
    
    arr = sequenceEven;
    initTree(1, 0, n-1);
    long long evenAns = tree[1]->maxArr;
    
    arr = sequenceOdd;
    initTree(1, 0, n-1);
    long long oddAns = tree[1] -> maxArr;
    
    return max(evenAns, oddAns);
}