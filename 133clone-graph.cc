class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node) return nullptr;
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;
    queue<UndirectedGraphNode *> q;
    q.push(node);
    m[node] = new UndirectedGraphNode(node->label);
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      for (auto nb: p->neighbors) {
        if (!m.count(nb)) {
          m[nb] = new UndirectedGraphNode(nb->label);
          q.push(nb);
        }
        m[p]->neighbors.push_back(m[nb]);
      }
    }
    return m[node];
  }
};

//recursive author : s2003zy
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
       if (!node) return node;
       if(hash.find(node) == hash.end()) {
           hash[node] = new UndirectedGraphNode(node -> label);
           for (auto x : node -> neighbors) {
                (hash[node] -> neighbors).push_back( cloneGraph(x) );
           }
       }
       return hash[node];
    }
};
