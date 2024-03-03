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
    
    int calcLen(ListNode* head)
    {
        if(!head) return 0;
        int c = 0;
        ListNode* temp = head;
        while(temp)
        {
           c++;
           temp = temp->next;
        }
       return c;
    }



    ListNode* removeNthFromEnd(ListNode* head, int k) {
        if(!head) return NULL;
        int len = calcLen(head);
        int pos = len - k;

        if(len == k)
        {
            ListNode* temp = head;
            head = head->next;
            return head;
        }

        ListNode* curr = head;
        for(int i = 1;i<pos;i++)
        {
            curr = curr->next;
        }
        // ListNode* t = curr->next;
        curr->next = curr->next->next;
        // delete(t);
        return head;
    }
};