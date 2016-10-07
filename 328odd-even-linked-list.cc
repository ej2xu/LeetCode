class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    if (head) {
      ListNode *odd = head, *even = head->next, *con = even;
      while (odd->next || even->next) {
        if (even->next) {
          odd->next = even->next;
          odd = odd->next;
        }
        if (odd->next) {
          even->next = odd->next;
          even = even->next;
        }
      }
      odd->next = con;
    }
    return head;
  }
};
