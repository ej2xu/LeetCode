class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    if (head && head->next) {
      ListNode *odd = head, *even = head->next, *con = even;
      while (true) {
        if (even->next) {
          odd->next = even->next;
          odd = odd->next;
        } else
          break;
        if (odd->next) {
          even->next = odd->next;
          even = even->next;
        } else {
          even->next = NULL;
          break;
        }
      }
      odd->next = con;
    }
    return head;
  }
};

class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    if (head) {
      ListNode *odd = head, *even = head->next, *con = even;
      while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
      }
      odd->next = con;
    }
    return head;
  }
};
