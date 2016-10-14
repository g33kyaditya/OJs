/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return head;
        
        unordered_map<RandomListNode*, RandomListNode*> m;
        
        RandomListNode * random = new RandomListNode(head->label);
        
        RandomListNode * temp1 = head;
        RandomListNode * temp2 = random;
        m[temp1] = temp2;
        temp1 = temp1->next;
        while (temp1 != NULL) {
            RandomListNode * newNode = new RandomListNode(temp1->label);
            temp2->next = newNode;
            temp2 = newNode;
            m[temp1] = temp2;
            temp1 = temp1->next;
        }
        
        temp1 = head;
        temp2 = random;
        
        while (temp1 != NULL) {
            if (temp1->random != NULL)
                temp2->random = m[temp1->random];
            else
                temp2->random = NULL;
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return random;
    }
};
