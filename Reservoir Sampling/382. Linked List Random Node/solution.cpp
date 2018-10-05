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
    ListNode* start;
    int len;
    Solution(ListNode* head) {
        start=head;
        if(!start)len=0;
        else{
            len=0;
            ListNode* tmp=start;
            while(tmp){
                len++;
                tmp=tmp->next;
            }
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ra=rand()%len;
        ListNode* obj = start;
        while(ra>0){
            ra--;
            obj=obj->next;
        }
        return obj->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
