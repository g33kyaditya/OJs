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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if (l1 == NULL && l2 == NULL)
            return NULL;
        
        int carry = 0;
        
        ListNode * head = new ListNode{-1};
        if (l1 || l2) {
            if (l1 && l2) {
                int s = l1->val + l2->val;
                carry = s/10;
                head->val = s%10;
                l1 = l1->next;
                l2 = l2->next;
            } 
            else if (l1) {
                int s = l1->val;
                head->val = s;
                l1 = l1->next;
            }
            else {
                int s = l2->val;
                head->val = s;
                l2 = l2->next;
            }
        }

        ListNode * temp = head;
        while(l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val;
            int p = (sum + carry)%10;
            carry = (sum + carry)/10;
            ListNode * newNode = new ListNode{p};
            temp->next = newNode;
            temp = temp->next;
    
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1) {
            while (l1 != NULL) {
                int s = (l1->val + carry)%10;
                carry = (l1->val + carry)/10;
                ListNode * newNode = new ListNode{s};
                temp->next = newNode;
                temp = temp->next;
                l1 = l1->next;
            }
        }
        
        if (l2) {
            while (l2 != NULL) {
                int s = (l2->val + carry)%10;
                carry = (l2->val + carry)/10;
                ListNode * newNode = new ListNode{s};
                temp->next = newNode;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        
        if (carry != 0) {
            ListNode * newNode = new ListNode{carry};
                temp->next = newNode;
        }
        
        return head;
    }
};
