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
    vector<int>leaf1,leaf2,node1,node2;

    void dfs(TreeNode* root, int sign){
        
        if(!root) return;
        
    //this root has no child then it is leaf
        if(!root->left && !root->right){
            
            if(sign==1) node1.push_back(root->val);
            
            else node2.push_back(root->val); 

        }

        dfs(root->left,sign);
        dfs(root->right,sign);

    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
         
        dfs(root1,1);
        dfs(root2,2);

        for(auto x : node1) cout<<x<<" ";
        cout<<endl;
        for(auto x : node2) cout<<x<<" ";
        cout<<endl;


    if(node1==node2) return 1;
    else return 0;


    }
};