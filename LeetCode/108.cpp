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
    TreeNode * createTree(vector<int>& nums, int lo, int hi) {
        
        if (lo > hi)
            return NULL;
        
        int mid = (hi + lo)/2;
        TreeNode * leftTree = createTree(nums, lo, mid-1);
        TreeNode * rightTree = createTree(nums, mid + 1, hi);
        
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = leftTree;
        root->right = rightTree;
        
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return NULL;
        //if (nums)
        TreeNode * root = createTree(nums, 0, nums.size()-1);
        return root;
    }
};
