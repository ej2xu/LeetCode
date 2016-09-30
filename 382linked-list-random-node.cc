class Solution {
public:
  int size;
  ListNode *head;
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode* h) {
    size = 0;
    head = h;
    for (; h; h = h->next)
      size++;
  }

  /** Returns a random node's value. */
  int getRandom() {
    ListNode *p = head;
    int t = rand()%size;
    while (t--)
      p = p->next;
    return p->val;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
