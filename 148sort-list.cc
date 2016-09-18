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
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next)
      return head;
    ListNode* slow = head, *fast = head->next, *mid;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    mid = sortList(slow->next);
    slow->next = NULL;
    return merge(sortList(head), mid);
  }
private:
  ListNode *merge(ListNode* h1, ListNode* h2) {
    ListNode head = ListNode(0), *cur = &head;
    while (h1 && h2) {
      if (h1->val <= h2->val) {
        cur->next = h1;
        h1 = h1->next;
      }
      else {
        cur->next = h2;
        h2 = h2->next;
      }
      cur = cur->next;
    }
    cur->next = h1 ? h1 : h2;
    return head.next;
  }
};

//botton up
class Solution {
public:
	ListNode *sortList(ListNode *head) {
    if (!head || !head->next)
      return head;
		ListNode* cur = head, *pre, *left, *right;
		int len = 0;
		while (cur) {
			cur = cur->next;
      len++;
		}

		ListNode dummy(0);
		dummy.next = head;
		for (int sz = 1; sz < len; sz <<= 1) {
      cur = dummy.next;
      pre = &dummy;
      while (cur) {
        left = cur;
        right = split(left, sz);
        cur = split(right, sz);
        merge(left, right, pre);
      }
    }
		return dummy.next;
	}
private:
	ListNode* split(ListNode *head, int n) {
    while (--n && head)
      head = head->next;
    if(!head) return NULL;
		ListNode *second = head->next;
		head->next = NULL;
		return second;
	}
	void merge(ListNode* l1, ListNode* l2, ListNode* &pre) {
    while (l1 && l2) {
    	if (l1->val > l2->val) {
    		pre->next = l2;
    		l2 = l2->next;
    	}
    	else {
    		pre->next = l1;
    		l1 = l1->next;
    	}
      pre = pre->next;
    }
    pre->next = l1 ? l1 : l2;
    while (pre->next)
      pre = pre->next;
	}
};

// MaskRay's natural merge sort

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (! head)
      return head;
    for(;;) {
      ListNode *p = head, *q, *r, *s, *head2 = NULL, *l = NULL;
      bool ok = true;
      while (p) {
        q = p;
        while (q->next && q->val <= q->next->val)
          q = q->next;
        q = q->next;
        s = r = q;
        if (s) {
          while (s->next && s->val <= s->next->val)
            s = s->next;
          s = s->next;
        }
        if (q)
          ok = false;
        while (p != q || r != s)
          if (r == s || p != q && p->val < r->val) {
            if (l)
              l->next = p;
            else
              head2 = p;
            l = p;
            p = p->next;
          } else {
            if (l)
              l->next = r;
            else
              head2 = r;
            l = r;
            r = r->next;
          }
        p = s;
      }
      l->next = NULL;
      head = head2;
      if (ok) break;
    }
    return head;
  }
};
