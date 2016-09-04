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
      slow->next = reverseList(slow->next);
      slow = slow->next;
      while (slow && head->val == slow->val) {
        slow = slow->next;
        head = head->next;
      }
      return slow == NULL;
    }
};

//recursive Solution
class Solution {
public:
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }

    bool check(ListNode* p) {
        if (NULL == p) return true;
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
};
