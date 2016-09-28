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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == NULL && l2 == NULL)
            return NULL;
        
        if (l1 == NULL)
            return l2;
        
        if (l2 == NULL)
            return l1;
        
        ListNode* head = NULL;
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        
        if (head1->val < head2->val) {
            head = head1;
            head1 = head1->next;
        }
        else {
            head = head2;
            head2 = head2->next;
        }
        ListNode* temp = head;
        while (head1 != NULL && head2!= NULL) {
            
            if (head1->val < head2->val) {
                temp->next = head1;
                temp = temp->next;
                head1 = head1->next;
            }
            else {
                temp->next = head2;
                temp = temp->next;
                head2 = head2->next;
            }
            
        }
        
        while (head1) {
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }
        
        while(head2) {
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }
        
        temp = NULL;
        return head;
    
    }
};
