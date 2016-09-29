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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        
        if (root->left == NULL && root->right == NULL) {
            if (sum - root->val == 0)
                return true;
        }
        
        bool ret = false;
        if (root->left) {
            ret = hasPathSum(root->left, sum - root->val);
            if (ret)
                return true;
        }
        if (root->right) {
            ret = hasPathSum(root->right, sum - root->val);
            if (ret)
                return true;
        }
        
        return false;
    }
};
