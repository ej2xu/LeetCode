class Solution {
public:
  vector<double> calcEquation(vector<pair<string, string>> eqs, vector<double>& vals, vector<pair<string, string>> queries) {
    int i = 0;
    for (; i < eqs.size(); i++) {
      adj[eqs[i].first].emplace_back(eqs[i].second, 1.0/vals[i]);
      adj[eqs[i].second].emplace_back(eqs[i].first, vals[i]);
    }
    i = 0;
    for (auto &x: adj)
      dfs(x.first, i++, 1.0);
    vector<double> res;
    for (auto &q: queries)
      if (!val.count(q.first) || !val.count(q.second))
        res.push_back(-1.0);
      else {
        auto &x = val[q.first], &y = val[q.second];
        if (x.first != y.first)
          res.push_back(-1.0);
        else
          res.push_back(x.second/y.second);
      }
    return res;
  }
private:
  unordered_map<string, vector<pair<string, double>>> adj;
  unordered_map<string, pair<int, double>> val;
  void dfs(string u, int id, double v) {
    if (!val.count(u)) {
      val[u] = {id, v};
      for (auto &x: adj[u])
        dfs(x.first, id, v * x.second);
    }
  }
};
