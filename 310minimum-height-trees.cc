class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n);
    vector<int> d(n, 0), res;
    queue<int> leaves;
    for (auto &e: edges) {
      d[e.first]++;
      d[e.second]++;
      adj[e.first].push_back(e.second);
      adj[e.second].push_back(e.first);
    }
    for (int i = 0; i < n; i++)
      if (d[i] <= 1)
        leaves.push(i);
    while (n > 2) {
      int s = leaves.size();
      n -= s;
      for (int i = 0; i < s; i++) {
        int x = leaves.front();
        leaves.pop();
        for (int y: adj[x])
          if (--d[y] == 1)
            leaves.push(y);
      }
    }
    if (n == 1)
      return vector<int>{leaves.front()};
    return vector<int>{leaves.front(), leaves.back()};
  }
};

//MaskRay's get diameter
class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    adj.resize(n);
    parent.resize(n);
    for (auto &e: edges) {
      adj[e.first].push_back(e.second);
      adj[e.second].push_back(e.first);
    }
    vector<int> ancestors;
    for (int v = bfs(bfs(0)); v != -2; v = parent[v])
      ancestors.push_back(v);
    vector<int> ret{ancestors[ancestors.size()/2]};
    if (ancestors.size() % 2 == 0)
      ret.push_back(ancestors[ancestors.size()/2-1]);
    return ret;
  }
private:
  vector<vector<int>> adj;
  vector<int> parent;
  int bfs(int u) {
    queue<int> q;
    int last = u;
    fill(parent.begin(), parent.end(), -1);
    parent[u] = -2;
    q.push(u);
    while (!q.empty()) {
      u = q.front();
      q.pop();
      last = u;
      for (int v: adj[u])
        if (parent[v] == -1) {
          parent[v] = u;
          q.push(v);
        }
    }
    return last;
  }
};
