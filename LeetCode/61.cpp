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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (head == NULL)
            return head;
        
        if (k == 0)
            return head;
        
        int total = 0;
        ListNode * temp = head;
        while (temp != NULL) {
            total++;
            temp = temp->next;
        }
        
        int f = (k)%total;
        temp = head;
        int i = 0;
        while (i < total-1) {
            temp = temp->next;
            i++;
        }
        temp->next = head;
        
        // Now circular
        
        temp = head;
        int z = total - f;
        while(z--) {
            temp = temp->next;
        }
        
        head = temp;
        temp = head;
        total--;
        while(total--) {
            temp = temp->next;
        }
        temp->next = NULL;
        return head;
    }
};
