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
    int rob(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        if (root->left == NULL && root->right == NULL)
            return root->val;
        
        int left = 0, right = 0;
        
        if (root->left)
            left = rob(root->left->left) + rob(root->left->right);
        if (root->right)
            right = rob(root->right->left) + rob(root->right->right);
        
        int max = 0;
        max = left + right + root->val;
        
        left = rob(root->left);
        right = rob(root->right);
        
        max = std::max(max, left + right);
        return max;
    }
};
