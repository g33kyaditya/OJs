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

    int foo(TreeNode* root, int sum) {
        
        if (root == NULL)
            return 0;
        
        if (root->left == NULL && root->right == NULL)
            return sum;

        int leftSum = 0, rightSum = 0;
        if (root->left)
            leftSum = foo(root->left, 10*sum + root->left->val);
        if (root->right)
            rightSum = foo(root->right, 10*sum + root->right->val);
        sum = leftSum + rightSum;
        return sum;
    }
    
    int sumNumbers(TreeNode* root) {
    
        if (root == NULL)
            return 0;
        
        if (root->left == NULL && root->right == NULL)
            return root->val;
        
        int ans = foo(root, root->val);
        return ans;
    }
};
