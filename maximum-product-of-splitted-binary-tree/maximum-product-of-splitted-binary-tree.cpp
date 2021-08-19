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
    long long int ans;
    long long int solve(TreeNode * root){
        if(!root)
            return 0;
        return solve(root->left)+ solve(root->right) + root->val;
    }
    long long int maxx(TreeNode * root,int sum){
        if(!root)
            return 0;
        long long int x = maxx(root->left,sum)+ maxx(root->right,sum) + root->val;
        ans = max(ans,(sum-x)*x);
        return x;
    }
    int maxProduct(TreeNode* root) {
        ans = 0;
        long long int sum = solve(root);
        maxx(root,sum);
        return ans%1000000007;
    }
};