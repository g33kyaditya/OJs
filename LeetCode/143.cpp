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
    void reorderList(ListNode* head) {
        if (head == NULL)
            return;
        ListNode * temp = head;
        
        stack<ListNode*> st;
        
        ListNode *slow = head, *fast = slow->next;
        if (fast) {
            while(slow && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
                if (fast == NULL)
                    break;
            }
        }
        if (slow->next != NULL)
            slow = slow->next;
        
        while(slow != NULL) {
            st.push(slow);
            slow = slow->next;
        }
        
        temp = head;
        while (!st.empty()) {
            ListNode * top = st.top();
            st.pop();
            if (!st.empty()) {
                ListNode * nextTop = st.top();
                nextTop->next = NULL;
            }
            ListNode * foo = temp->next;
            temp->next = top;
            top->next = foo;
            
            if (temp->next != NULL) {
                if (temp->next->next != NULL)
                    temp = temp->next->next;
            }
        }
        if (temp != NULL)
            temp->next = NULL;
    }
};
