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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
       this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        
        ListNode * temp = head;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }
        
        int t = rand()%count;
        temp = head;
        while (t >= 1) {
            temp = temp->next;
            t--;
        }
        return temp->val;
    }
private:
    ListNode * head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
