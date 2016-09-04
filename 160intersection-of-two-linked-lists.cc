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
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
      Set<ListNode *> visited;
      while (a && b) {
        if (visited.count(a))
          return a;
        visited.insert(a);
        a = a->next;
        if (visited.count(b))
          return b;
        visited.insert(b);
        b = b->next;
      }
      while (a) {
        if (visited.count(a))
          return a;
        visited.insert(a);
        a = a->next;
      }
      while (b) {
        if (visited.count(b))
          return b;
        visited.insert(b);
        b = b->next;
      }
      return NULL;
    }
};

//dong.wang's short solution
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *cur1 = headA, *cur2 = headB;
    while(cur1 != cur2) {
        cur1 = cur1?cur1->next:headB;
        cur2 = cur2?cur2->next:headA;
    }
    return cur1;
}

//MaskRay's Solution
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
    int d = 0;
    for (ListNode *p = a; p; p = p->next) d++;
    for (ListNode *p = b; p; p = p->next) d--;
    while (d > 0) a = a->next, d--;
    while (d < 0) b = b->next, d++;
    while (a != b) a = a->next, b = b->next;
    return a;
  }
};
