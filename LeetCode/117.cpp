/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode* > q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            TreeLinkNode* cur = q.front();
            q.pop();
            if (cur == NULL)
            {
                if (q.empty())
                    break;
                if (q.front() == NULL)
                    break;
                q.push(NULL);
                continue;
            }
            if (cur->left != NULL)
                q.push(cur->left);
            if (cur->right != NULL)
                q.push(cur->right);
            cur->next = q.front();
        }
        return;
    }
};
