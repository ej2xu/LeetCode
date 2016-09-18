class Solution {
public:
  ListNode* insertionSortList(ListNode* head) {
    if (!head)
      return head;
    ListNode *q = head->next, *p, **r;
    head->next = NULL;
    while (q) {
      p = q->next;
      r = &head;
      while (*r && q->val > (*r)->val)
        r = &(*r)->next;
      q->next = *r;
      *r = q;
      q = p;
    }
    return head;
  }
};

class Solution {
public:
  ListNode* insertionSortList(ListNode* head) {
    if (!head)
      return head;
    ListNode *p = head, *q, **r;
    while (q = p->next) {
      if (q->val >= p->val)
        p = q;
      else {
        p->next = q->next;
        r = &head;
        while (q->val > (*r)->val)
          r = &(*r)->next;
        q->next = *r;
        *r = q;
      }
    }
    return head;
  }
};
