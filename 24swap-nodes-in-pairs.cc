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
   ListNode *swapPairs(ListNode *head) {
     ListNode **p = &head;
     while (*p && (*p)->next) {
       ListNode *q = (*p)->next;
       (*p)->next = q->next;
       q->next = *p;
       *p = q;
       p = &(*p)->next->next;
     }
     return head;
   }
 };

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode dummy(0), *cur = &dummy, *first, *second;
    cur->next = head;
    while ((first=cur->next) && (second=cur->next->next)) {
      first->next = second->next;
      second->nnext = first;
      cur->next = second;
      cur = first;
    }
    return dummy.next;
  }
};
