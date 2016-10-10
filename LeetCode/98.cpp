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
    bool check(TreeNode * root, long long int lo, long long int hi) {
        if (root == NULL)
            return true;
        
        if (root->val >= hi || root->val <= lo)
            return false;
        
        if (!check(root->left, lo, root->val) || !check(root->right, root->val, hi))
            return false;
        
        return true;
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        
        return check(root, -1000000000000, 10000000000000);
    }
};
