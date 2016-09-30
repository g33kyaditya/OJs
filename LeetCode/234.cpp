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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode * temp = head;
        while (temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }
        
        while (!st.empty() && head != NULL) {
            if (head->val != st.top())
                return false;
            
            head = head->next;
            st.pop();
        }
        return true;
    }
};
