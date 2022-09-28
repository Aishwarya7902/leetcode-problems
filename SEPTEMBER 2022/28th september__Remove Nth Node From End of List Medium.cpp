PROBLEM:https://leetcode.com/problems/remove-nth-node-from-end-of-list/
VIDEO:

/*MY INITIAL APPROACH 
pseudo code: did  a simple thing 
1.find out size of ll= n let's say 
2.since we have to remove kth node from end....it means there are  n-k nodes right from starting
3.move pointer to position such that it is at a place just before the node which we have to delete....lets call it as prev
4.the node which we have to delete ....let's call it as a curr
5.now what we have to do is....prev ke next me curr ke next ko dal do
6.and curr ke next ko null kar do

EDGE CASES:
1.if one node is there and k=1 ...after deleting no node will be there...simply return null
2.if k==n it means we have to remove the first node and return head->next
tc: O(N)
sc: O(1)
*/

class Solution {
  
private:
  int Length(ListNode* head){
    if(!head)return 0;
    int cnt=0;
        ListNode* temp=head;
      while(temp->next){
        cnt++;
        temp=temp->next;
      }
    return ++cnt;
  }
  
public:
 
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      
      int size=Length(head);
      if(size==1 && n==1)return NULL;
      if(n==size){
        ListNode* t=head->next;
        head->next=NULL;
        return t;
      }
      ListNode* prev;
      ListNode* temp;
      temp=head;
      int cnt=1;
      while(cnt<size-n){
        temp=temp->next;
        cnt++;
      }
      prev=temp->next;
      temp->next=prev->next;
      prev->next=NULL;
      return head;
    }
};
