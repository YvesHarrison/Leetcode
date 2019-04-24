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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 0) return head;
        int length = 0;
        ListNode* d = new ListNode(0);
        d->next = head;
        ListNode* fast = d;
        ListNode* slow = d;
        while(fast){
            fast = fast->next;
            if(length>n)slow = slow->next;
            length++;
        }
        slow->next = slow->next->next;
        return d->next;
    }
};
