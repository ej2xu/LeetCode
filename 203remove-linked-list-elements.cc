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
    ListNode* removeElements(ListNode* head, int val) {
      if (!head) return head;
      ListNode dummy(0), *cur = &dummy, tmp;
      cur->next = head;
      while (true) {
        while (cur->next && cur->next->val == val) {
          tmp = cur->next;
          cur->next = tmp->next;
          delete tmp;
        }
        if (!cur->next) break;
        cur = cur->next;
      }
      return dummy.next;
    }
};
