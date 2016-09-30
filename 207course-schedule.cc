class Solution {
public:
  bool canFinish(int num, vector<pair<int, int>>& pres) {
    vector<vector<int>> adj(num);
    vector<bool> visited(num, false), onpath(num, false);
    for (auto &e: pres)
      adj[e.first].push_back(e.second);
    for (int v = 0; v < num; v++)
      if (!visited[v] && hascycle(adj, visited, onpath, v))
        return false;
    return true;
  }
private:
  bool hascycle(vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &onpath, int v) {
    visited[v] = onpath[v] = true;
    for (int u: adj[v])
      if (onpath[u] || !visited[u] && hascycle(adj, visited, onpath, u))
        return true;
    return onpath[v] = false;
  }
};

//Kahn's algorithm
class Solution {
public:
  bool canFinish(int num, vector<pair<int, int>>& pres) {
    vector<vector<int>> adj(num);
    vector<int> d(num, 0);
    int top = -1, count = 0;
    for (auto &e: pres) {
      d[e.first]++;
      adj[e.second].push_back(e.first);
    }
    for (int i = 0; i < num; i++)
      if (! d[i])
        d[i] = top, top = i;
    while (top != -1) {
      int x = top;
      top = d[top];
      count++;
      for (auto y: adj[x])
        if (! --d[y])
          d[y] = top, top = y;
    }
    return count == num;
  }
};
