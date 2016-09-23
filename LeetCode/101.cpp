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
    
    bool isMirror(TreeNode * a, TreeNode * b) {
        
        if (a == NULL && b == NULL)
            return true;
        
        if (a && b && a->val == b->val) {
            return isMirror(a->left, b->right) && isMirror(a->right, b->left);
        }
        return false;
        
    }

    bool isSymmetric(TreeNode* root) {
    
        if (root == NULL)
            return true;
        
        if (isMirror(root, root))
            return true;
        return false;
    }
};
