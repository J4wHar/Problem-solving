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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* headAns = ans;
        bool carry = 0;
        while(l1 && l2){
            int cur = l1->val + l2->val + carry;
            if(cur>=10){
                ListNode* x = new ListNode(cur%10);
                carry = 1;
                ans->next = x;
            }else{
                ListNode* x = new ListNode(cur);
                carry = 0;
                ans->next = x;
            }
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int cur = l1->val + carry;
            if(cur == 10){
                ListNode* x = new ListNode(0);
                carry = 1;
                ans->next = x;
            }else{
                ListNode* x = new ListNode(cur);
                carry = 0;
                ans->next = x;
            }
            ans = ans->next;
            l1 = l1->next;
        }
        while(l2){
            int cur = l2->val + carry;
            if(cur == 10){
                ListNode* x = new ListNode(0);
                carry = 1;
                ans->next = x;
            }else{
                ListNode* x = new ListNode(cur);
                carry = 0;
                ans->next = x;
            }
            ans = ans->next;
            l2 = l2->next;
        }
        if(carry){
            ans->next = new ListNode(1);
        }
        return headAns->next;
    }
};