#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int longestPath(TreeNode* root, char pre, int n)
    {
        if(root == NULL)    
        { 
            return n-1;
        }
        
        int r_len, l_len;
        if(pre == 'L')
        {
            l_len = longestPath(root->left, 'L', 1);
            r_len = longestPath(root->right, 'R', n+1);
        }
        else if(pre == 'R')
        {
            l_len = longestPath(root->left, 'L', n+1);
            r_len = longestPath(root->right, 'R', 1);
        }
        else
        {
            l_len = longestPath(root->left, 'L', 1);
            r_len = longestPath(root->right, 'R', 1);
        }

        return l_len > r_len ? l_len : r_len;
    }

    int longestZigZag(TreeNode* root) {
        return longestPath(root, ' ', 0);
    }
};