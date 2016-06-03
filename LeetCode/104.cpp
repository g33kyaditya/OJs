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
    Solution() {depth = 0;}
    int maxDepth(TreeNode* root) {
    
        if (root == NULL)
            return 0;
        else if (root->left != NULL && root->right != NULL)
            depth = 1 + std::max(maxDepth(root->left), maxDepth(root->right));
        else if (root->left != NULL)
            depth = 1 + maxDepth(root->left);
        else
            depth = 1 + maxDepth(root->right);
    
    
    
        return depth;
    }
    private:
        int depth;
};
