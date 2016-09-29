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
    
    void paths(TreeNode* root, string cur, vector<string>& ans) {
        if (root->left == NULL && root->right == NULL) {
            cur = cur + to_string(root->val);
            ans.push_back(cur);
            return;
        }
        
        cur = cur + to_string(root->val) + "->";
        if (root->left)
            paths(root->left, cur, ans);
        if (root->right)
            paths(root->right, cur, ans);
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL)
            return ans;
        
        string ret = "";
        paths(root, ret, ans);
        return ans;
        
    }
};
