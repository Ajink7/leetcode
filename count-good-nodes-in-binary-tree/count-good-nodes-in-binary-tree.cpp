/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode *root, int m){
        int x = 0;
        if(root==NULL)
            return 0;
        if(root->val>=m)
            x=1;
        return x + solve(root->left,max(m,root->val)) + solve(root->right,max(m,root->val));
    }
    int goodNodes(TreeNode* root) {
        return solve(root,root->val);
    }
};