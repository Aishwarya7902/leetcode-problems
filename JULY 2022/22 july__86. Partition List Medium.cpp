/*
APPROACH 1 Runtime: 11 ms, faster than 39.33% of C++ online submissions for Partition List.
Memory Usage: 10.1 MB, less than 94.54% of C++ online submissions for Partition List.


VISIT :https://leetcode.com/problems/partition-list/discuss/29185/Very-concise-one-pass-solution (DRY RUN KARO SAB CLEAR HO JAYEGA😉)
TC:O(N)
SC:O(1)
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      ListNode node1(0) ,node2(0);
      ListNode *p1=&node1,*p2=&node2; 
        while(head){
            if(head->val<x){
                p1=p1->next=head;
            }
            else{
                p2=p2->next=head;
            }
            head=head->next;
        }
        p2->next=NULL;
        p1->next=node2.next;
        return node1.next;
    }
};
