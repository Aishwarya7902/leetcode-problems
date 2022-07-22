*************************MY WRONG ASSUMPTION FRO THE QUESTION**************
at first glance i thought we have to move all no less thn x behind x and greater than or equal to x beyond x...which was totally wrong
AS STATED IN THE QUESTION :   You should preserve the original relative order of the nodes in each of the two partitions.
    HENCE original relative order of the nodes MUST BE MAINTAINED👀

/*
APPROACH 1 Runtime: 11 ms, faster than 39.33% of C++ online submissions for Partition List.
Memory Usage: 10.1 MB, less than 94.54% of C++ online submissions for Partition List.


VISIT :https://leetcode.com/problems/partition-list/discuss/29185/Very-concise-one-pass-solution (DRY RUN KARO SAB CLEAR HO JAYEGA😉)

PSEUDO CODE: 
1.create two empty  node as node1 and node2
2.pointer p1 points to node1 and pointer p2 points to p2
3.while head is not null traverse the linked list
from here we are in while loop
4.if head ki value is less than x point p1->next to head and then move p1 to head
5.if head ki value is greater  than oor equal to x point p2->next to head and then move p2 to head
6.head=head->next
now we are out of while loop
7.p2->next==null coz p2 always connects nodes which are greater than or equal to x...hence at last p2 will point to the greatest no of linked list...hence 
there will be no node after that...hence its next will be null.
8.node2->next points to the first node which is greater than equal to x
after while loop p1 will be at the last node which is less than x..hence all nodes after that will be greater than or equal to x.
hence 
p1->next=node2->next
9.node1->next points to the first node which is less than x...hence return it....coz it will act as head.


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
                p1->next=head;
                p1=p1->next;
            }
            else{
                p2->next=head;
                p2=p2->next;
            }
            head=head->next;
        }
        p2->next=NULL;
        p1->next=node2.next;
        return node1.next;
    }
};

/*approach 2: same above code but a bit faster coz we handled memory leak
Runtime: 7 ms, faster than 73.71% of C++ online submissions for Partition List.
Memory Usage: 10.3 MB, less than 32.53% of C++ online submissions for Partition List.

TC:O(N)
SC:O(1)
BEAUTIFUL EXPLAINATION __VIDEO:  https://www.youtube.com/watch?v=b4FeEwAGDtU
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      ListNode *node1= new ListNode (0) ;
      ListNode *node2= new ListNode (0) ;

      ListNode *p1=node1,*p2=node2; 
        while(head){
            if(head->val<x){
                p1->next=head;
                p1=p1->next;
            }
            else{
                p2->next=head;
                p2=p2->next;
            }
            head=head->next;
        }
        p2->next=NULL;
        p1->next=node2->next;
        head=node1->next;
        delete node1,node2;
        return head;
    }
};

