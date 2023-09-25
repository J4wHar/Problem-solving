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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode* slow1 = head;
        while(slow && fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                while(slow != slow1){
                    slow = slow->next;
                    slow1 = slow1->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};