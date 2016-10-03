class Solution {
public:
  void connect(TreeLinkNode *p) {
    while (p) {
      TreeLinkNode *head = NULL, *prev = NULL;
      for (; p; p = p->next) {
        if (p->left) {
          if (prev)
            prev->next = p->left;
          else
            head = p->left;
          prev = p->left;
        }
        if (p->right) {
          if (prev)
            prev->next = p->right;
          else
            head = p->right;
          prev = p->right;
        }
      }
      p = head;
    }
  }
};

class Solution {
public:
  void connect(TreeLinkNode *p) {
    TreeLinkNode dumhead(0);
    dumhead.next = p;
    while (p) {
      TreeLinkNode *tail = &dumhead;
      dumhead.next = NULL;
      for (; p; p = p->next) {
        if (p->left) {
          tail->next = p->left;
          tail = tail->next;
        }
        if (p->right) {
          tail->next = p->right;
          tail = tail->next;
        }
      }
      p = dumhead.next;
    }
  }
};
