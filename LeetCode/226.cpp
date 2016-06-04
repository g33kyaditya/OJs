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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        TreeNode *l, *r;
        l = invertTree(root->left);
        r = invertTree(root->right);
        root->left = r;
        root->right = l;
        return root;
    }

};
