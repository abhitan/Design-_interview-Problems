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
   
   ListNode *findMid(ListNode *head)
   {
       if(!head) return NULL;
       ListNode *slow = head;
       ListNode *fast = head;

       while(fast and fast->next)
       {
           slow = slow->next;
           fast = fast->next->next;
       }
       return slow;
   }

   ListNode *revList(ListNode *head)
   {
       ListNode *nex = NULL;
       ListNode *prev = NULL;
       ListNode *curr = head;

       while(curr)
       {
           nex = curr->next;
           curr->next = prev;
           prev = curr;
           curr = nex;
       }
       return prev;
   }

   bool compare(ListNode *head1,ListNode *head2)
   {
       while(head1 != NULL and head2 != NULL)
       {
           if(head1->val != head2->val)
           {
               return false;
           }
           head1 = head1->next;
           head2 = head2->next;
       }
       return true;
   }








    bool isPalindrome(ListNode* head) {
        if(head == NULL and head->next == NULL)
        {
            return true;
        }
        ListNode *h = head;
        ListNode *mid = findMid(head);
        ListNode *h2 = revList(mid);

        return compare(h,h2);
    }
};