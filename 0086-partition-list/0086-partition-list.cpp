/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode();
        ListNode* more = new ListNode();
        ListNode* ans = less;
        ListNode* headMore = more;
        while(head){
            if(head->val >= x){
                ListNode* cur = new ListNode(head->val);
                more->next = cur;
                more = more->next;
            }else{
                ListNode* cur = new ListNode(head->val);
                less->next = cur;
                less = less->next;
            }
            head = head->next;
        }
        less->next = headMore->next;
        return ans->next;
    }
};