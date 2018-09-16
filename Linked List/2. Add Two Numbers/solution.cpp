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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int tmp=0;
        ListNode* sum1=l1;
        ListNode* sum2=l2;
        ListNode* dummyRoot = new ListNode(0);
        ListNode* res = dummyRoot;
        while(sum1!=nullptr && sum2!=nullptr){
            tmp+=(sum1->val+sum2->val);
            if (tmp<10){
                res->next=new ListNode(tmp);
                tmp=0;
            }
            else{
                res->next=new ListNode(tmp-10);
                tmp=1;
            }
            sum1=sum1->next;
            sum2=sum2->next;
            res=res->next;
        }
        while(sum1!=nullptr){
            if(tmp!=0){
                if(sum1->val+1<10){
                    res->next=new ListNode(sum1->val+1);
                    tmp=0;
                }
                else res->next=new ListNode(sum1->val+1-10);
            }
            else{
                res->next=new ListNode(sum1->val);
            }
            sum1=sum1->next;
            res=res->next;
        }
        while(sum2!=nullptr){
            if(tmp!=0){
                if(sum2->val+1<10){
                    res->next=new ListNode(sum2->val+1);
                    tmp=0;
                }
                else res->next=new ListNode(sum2->val+1-10);
            }
            else{
                res->next=new ListNode(sum2->val);
            }
            sum2=sum2->next;
            res=res->next;
        }
        if(tmp!=0){
            res->next=new ListNode(1);
        }
        res=dummyRoot->next;
        delete dummyRoot;
        return res;
    }
};
