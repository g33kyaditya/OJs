/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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


    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec;
        if (head == NULL)
            return NULL;

        while (head != NULL) {
            vec.push_back(head->val);
            head = head->next;
        }
        
        if (vec.empty())
            return NULL;
        TreeNode * root = createTree(vec, 0, vec.size()-1);
        return root;
    }
};
