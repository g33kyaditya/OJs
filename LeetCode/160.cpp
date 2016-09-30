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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int len1 = 0;
        int len2 = 0;
        ListNode * tempA = headA;
        ListNode * tempB = headB;
        while (tempA != NULL) {
            len1++;
            tempA = tempA->next;
        }
        
        while (tempB != NULL) {
            len2++;
            tempB = tempB->next;
        }
        
        if (len1 > len2) {
            int diff = len1 - len2;
            while (diff--)
                headA = headA->next;
        }
        
        if (len2 > len1) {
            int diff = len2 - len1;
            while (diff--)
                headB = headB->next;
        }
        
        while (headA != NULL && headB != NULL) {
            if (headA == headB)
                return headA;
            
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};
