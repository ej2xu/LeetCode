/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode* sortedListToBST(ListNode* head) {
    ListNode *l = head;
    int n = 0;
    while (head) {
      head = head->next;
      n++;
    }
    return f(n, l);
  }
private:
  TreeNode *f(int n, ListNode *&l) {
    if (!n) return NULL;
    auto x = new TreeNode(0);
    x->left = f(n/2, l);
    x->val = l->val;
    l = l->next;
    x->right = f(n-n/2-1, l);
    return x;
  }
};
