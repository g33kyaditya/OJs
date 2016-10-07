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
    TreeNode * foo(TreeNode * root) {
        if (root == NULL) return root;
        
        if (root->left == NULL && root->right == NULL)  return root;
        
        TreeNode * left = foo(root->left);
        TreeNode * right = foo(root->right);
        
        if (left) {
            left->right = root->right;
        }
        if (root->left)
            root->right = root->left;
        
        root->left = NULL;
        return (right) ? right : left;
    }

    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        
        foo(root);
    }
};
