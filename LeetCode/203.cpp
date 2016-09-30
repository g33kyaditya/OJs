/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * temp = head;
        ListNode * back = head;
        
        while (head && head->val == val)
            head = head->next;
        
        while (temp != NULL) {
            if (temp->val == val) {
                back->next = temp->next;
                temp = temp->next;
                continue;
            }
            back = temp;
            temp = temp->next;
        }
        return head;
    }
};
