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
      ListNode *cur, *pre = NULL;
      while(h) {
        cur = h->next;
        h->next = pre;
        pre = h;
        h = cur;
      }
      return pre;
    }

    bool isPalindrome(ListNode* head) {
      if (!head || !head->next)
        return true;
      ListNode *slow = head, *fast = head;
      while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
      }
      slow->next = reverseList()

      return NULL;
    }
};
