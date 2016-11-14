/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans(TreeNode* root, int& sum) {
        
        if (root == NULL)
            return 0;
        
        int l = ans(root->left, sum);
        int r = ans(root->right, sum);
        
        int m = max(max(l, r) + root->val, root->val);

        int m2 = max(m, l + r + root->val);
        sum = max(sum, m2);
        return m;
    }
    
    
    int maxPathSum(TreeNode* root) {
    
        if (root == NULL)
            return 0;

        int res = INT_MIN;
        ans(root, res);
        return res;
       
    }
};
