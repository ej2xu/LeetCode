class Solution {
public:
  vector<int> findOrder(int num, vector<pair<int, int>>& pres) {
    vector<vector<int>> adj(num);
    vector<bool> visited(num, false), onpath(num, false);
    vector<int> res(num);
    int pos = num-1;
    for (auto &e: pres)
      adj[e.second].push_back(e.first);
    for (int v = 0; v < num; v++)
      if (!visited[v] && hascycle(adj, visited, onpath, v, res, pos))
        return vector<int>{};
    return res;
  }
private:
  bool hascycle(vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &onpath, int v, vector<int> &res, int &pos) {
    visited[v] = onpath[v] = true;
    for (int u: adj[v])
      if (onpath[u] || !visited[u] && hascycle(adj, visited, onpath, u, res, pos))
        return true;
    res[pos--] = v;
    return onpath[v] = false;
  }
};

//Kahn's algorithm
class Solution {
public:
  vector<int> findOrder(int num, vector<pair<int, int>>& pres) {
    vector<vector<int>> adj(num);
    vector<int> d(num, 0), res;
    int top = -1, count = 0;
    for (auto &e: pres) {
      d[e.first]++;
      adj[e.second].push_back(e.first);
    }
    for (int i = 0; i < num; i++)
      if (!d[i]) {
        res.push_back(i);
        d[i] = top, top = i;
      }
    while (top != -1) {
      int x = top;
      top = d[top];
      count++;
      for (auto y: adj[x])
        if (! --d[y]) {
          res.push_back(y);
          d[y] = top, top = y;
        }
    }
    return res.size() == num ? res : vector<int>{};
  }
};
