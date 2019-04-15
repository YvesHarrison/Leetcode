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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* tmp = head;
        while(head){
            if(head->next){
                while(head->next&&head->val == head->next->val){
                    head->next = head->next->next;
                }
            }
            head = head->next;
        }
        return tmp;
    }
};
