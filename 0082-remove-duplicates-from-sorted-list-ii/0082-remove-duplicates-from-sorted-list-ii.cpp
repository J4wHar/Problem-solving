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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> hashMap;
        ListNode* ans = new ListNode();
        ListNode* headAns = ans;
        while(head){
            ++hashMap[head->val];
            head = head->next;
        }
        for(auto x: hashMap){
            if(x.second == 1){
                ListNode* node = new ListNode(x.first);
                ans->next = node;
                ans = ans->next;
            }
        }
        return headAns->next;
    }
};