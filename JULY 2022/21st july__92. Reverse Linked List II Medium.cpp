/*PROBLEM : https://leetcode.com/problems/reverse-linked-list-ii/
BRUTE FORCE (GETTING TLE)
pseudo code:
1.find one node before left which we call as prev
2.find one node after right which we call as after
3.reverse list between left and right
4.set prev->next with the newhead returned by the reverse linked list function 
5. the list which we reversed from left point to right point...find it's last node and to its next add the after node

for more clarity see: https://youtu.be/tHKp8UuOkm4

*


class Solution {
private:
   ListNode* reverse(ListNode* head)
    {
        if(head==NULL || head->next==NULL ){
            return head;
        }
        ListNode* temp=head->next;
        ListNode* currAns=reverse(temp);
        head->next=NULL;
        temp->next=head;
        return currAns;
        
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)return head;
      ListNode* temp1,*temp2,*prev,*after;
        int l=1,r=1;
        temp1=temp2=head;
        while(l!=left){
            prev=temp1;
            temp1=temp1->next;
            l++;
        }
        while(r!=right){
            
            temp2=temp2->next;
            r++;
        }
        
        after=temp2->next;
        
        temp2->next=NULL;
        if(prev)prev->next=NULL;
        ListNode* newHead=reverse(temp1);
        if(prev)prev->next=newHead;
        ListNode* curr=newHead;
        while(curr->next){
            curr=curr->next;
        }
        curr->next=after;
        if(left==1)
            return newHead;
        else
            return head;
        
        
    }
};
