/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

  }
};




// Clone Graph
class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (! node) return nullptr;
    map<UndirectedGraphNode *, UndirectedGraphNode *> m;
    stack<UndirectedGraphNode *> st;
    st.push(node);
    m[node] = new UndirectedGraphNode(node->label);
    while (! st.empty()) {
      auto x = st.top();
      st.pop();
      for (auto y: x->neighbors) {
        if (! m.count(y)) {
          m[y] = new UndirectedGraphNode(y->label);
          st.push(y);
        }
        m[x]->neighbors.push_back(m[y]);
      }
    }
    return m[node];
  }
};
