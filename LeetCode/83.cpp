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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * temp = head;
        ListNode * del;
        if (head == NULL)
            return head;
        
        int val = head->val;
        ListNode * prev = head;
        temp = temp->next;
        while (temp != NULL) {
            if (val == temp->val) {
                del = temp;
                prev->next = temp->next;
                temp = temp->next;
                delete del;
            }
            else {
                prev = temp;
                val = prev->val;
                temp = temp->next;
            }
        }
        return head;
    }
};
