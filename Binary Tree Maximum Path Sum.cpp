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
private:
    int dfs(TreeNode* root, int& res) {
        if(!root) return 0;
        int l = max(0,dfs(root->left,res));
        int r = max(0,dfs(root->right,res));
        res = max(l+r+root->val, res);
        return root->val + max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = -INT_MAX;
        dfs(root,res);
        return res;
    }
};