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
        ListNode* less = new ListNode(0);
        ListNode* great = new ListNode(0);
        ListNode* lhead = less;
        ListNode* ghead = great;
        while(head!= NULL){
            if(head->val >= x) {
                great->next = head;
                great = great->next;
            }
            else{
                less->next = head;
                less = less->next;
            } 
            head = head->next;
        }
        great->next = NULL;//no this line will cause time limit exceed when end of great list is not the end of the original list
        less->next = ghead->next;
        return lhead->next;
    }
};
