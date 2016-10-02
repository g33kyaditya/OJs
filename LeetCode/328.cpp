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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return head;
        
        ListNode * oddHead = head;
        ListNode * evenHead = head->next;
        
        ListNode * cur = oddHead;
        ListNode * next = evenHead;
        while (cur != NULL && next != NULL) {
            ListNode * temp = next;
            cur->next = next->next;
            cur = temp;
            next = cur->next;
        }
        
        ListNode * temp = oddHead;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = evenHead;
        
        return oddHead;
    }
};
