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
    
    TreeNode * getNewNode(int val) {
        TreeNode * node = new TreeNode(val);
        return node;
    }
    
    TreeNode * build(vector<int>& preorder, vector<int>& inorder, int plo, int phi, int ilo, int ihi) {
        
        if (plo > phi || ilo > ihi)
            return NULL;
        
        if (ilo == ihi) {
            return getNewNode(inorder[ilo]);
        }
        
        int in;
        for (int i = ilo; i <= ihi; i++) {
            if (inorder[i] == preorder[plo]) {
                in = i;
                break;
            }
        }
        
        int total = in - ilo;
        TreeNode * root = getNewNode(preorder[plo]);
        
        TreeNode * left = build(preorder, inorder, plo+1, plo+total, ilo, in-1);
        TreeNode * right = build(preorder, inorder, plo+total+1, phi, in+1, ihi);
        
        root->left = left;
        root->right = right;
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;
        
        TreeNode * root = build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
        
        return root;
    }
};
