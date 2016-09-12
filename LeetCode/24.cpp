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
    ListNode* swapPairs(ListNode* head) {
    
        ListNode * temp = head;
        ListNode * prev = NULL;
        while (temp != NULL && temp->next != NULL) {
            ListNode * curr = temp;
            ListNode * next = curr->next;
            curr->next = next->next;
            next->next = curr;
            
            if (prev == NULL)
                head = next;
            else
                prev->next = next;
            
            prev = temp;
            temp = temp->next;
        }
        return head;
    
    }
};
