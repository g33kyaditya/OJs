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
    ListNode* partition(ListNode* head, int x) {
        queue<ListNode *> small;
        queue<ListNode *> greater;
        bool emp = false;
        
        if (head == NULL)
            return head;
        
        ListNode * runner = head;
        ListNode * orig = NULL;
        while (runner != NULL) {
            if (runner->val < x)
                small.push(runner);
            else
                greater.push(runner);
            
            runner = runner->next;
        }
        
        if (small.empty())
            emp = true;
        
        if (!small.empty()) {
            head = small.front();
            small.pop();
        }
        
        ListNode * temp = head;
        while(!small.empty()) {
            temp->next = small.front();
            small.pop();
            temp = temp->next;
        }
        
        if (!emp) {
            while(!greater.empty()) {
                temp->next = greater.front();
                greater.pop();
                temp = temp->next;
            }
            temp->next = NULL;
        }
        
        else {
            return head;
        }
        
        
        return head;
        
    }
};
