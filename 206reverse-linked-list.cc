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
    ListNode* reverseList(ListNode* h) {
      ListNode* newH, *t = NULL;
      while(h) {
        newH = h->next;
        h->next = t;
        t = h;
        h = newH;
      }
      return t;
    }
};
