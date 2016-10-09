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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        bool left = true;
        while(!q.empty()) {
            int size = q.size();
            vector<int>vec;
            for (int i = 0; i < size; i++) {
                TreeNode * top = q.front();
                vec.push_back(top->val);
                q.pop();
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }
            if (!left) {
                std::reverse(vec.begin(), vec.end());
                left = true;
            }
            else
                left = false;

            ans.push_back(vec);
        }
        return ans;
    }
};
