// 9ms
class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    if (!k) return 0;
    int l = prices.size();
    if (k >= l/2) return quicksolve(prices);
    vector<int> b(k, INT_MIN), s(k, 0);
    for (int p : prices) {
      b[0] = max(b[0], -p), s[0] = max(s[0], b[0]+p);
      for (int i = 0; i < k; i++) {
        b[i] = max(b[i], s[i-1]-p);
        s[i] = max(s[i], b[i]+p);
      }
    }
    return s[k-1];
  }
private:
  int quicksolve(vector<int>& prices) {
    int i = 0, profit = 0, s = prices.size();
    while (i < s-1) {
      while (i < s-1 && prices[i] >= prices[i+1]) i++;
      int valley = prices[i];
      while (i < s-1 && prices[i] <= prices[i+1]) i++;
      int peak = prices[i];
      profit += peak-valley;
    }
    return profit;
  }
};

// 9ms
// f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions.
// f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj-1]) { jj in range of [1, ii-1] }
//          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj-1] - prices[jj]))
// f[0, ii] = 0; 0 times transation makes 0 profit
// f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    int s = prices.size();
    if (k >= s/2) return quicksolve(prices);
    if (!s) return 0;
    vector<vector<int>> f(k+1, vector<int>(s, 0));
    for (int kk = 1; kk <= k; kk++) {
      int ma = -prices[0];
      for (int ii = 1; ii < s; ii++) {
        f[kk][ii] = max(f[kk][ii-1], prices[ii] + ma);
        ma = max(ma, f[kk-1][ii-1] - prices[ii]);
      }
    }
    return f[k][s-1];
  }
private:
  int quicksolve(vector<int>& prices) {
    int i = 0, profit = 0, s = prices.size();
    while (i < s-1) {
      while (i < s-1 && prices[i] >= prices[i+1]) i++;
      int valley = prices[i];
      while (i < s-1 && prices[i] <= prices[i+1]) i++;
      int peak = prices[i];
      profit += peak-valley;
    }
    return profit;
  }
};

//
class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    if (!k) return 0;
    int s = prices.size(), v = 0, p = 0, res = 0;
    priority_queue<int> profits;
    stack<pair<int, int>> vps;
    while (p < s-1) {
      for (v = p; v < s-1 && prices[v] >= prices[v+1]; v++);
      for (p = v; p < s-1 && prices[p] <= prices[p+1]; p++);
      int curv = prices[v], curp = prices[p];
      while (!vps.empty() && curv < vps.top().first) {
        profits.push(vps.top().second-vps.top().first);
        vps.pop();
      }
      while (!vps.empty() && curp > vps.top().second) {
        profits.push(vps.top().second - curv);
        curv = vps.top().first;
        vps.pop();
      }
      vps.push({curv, curp});
    }
    while (!vps.empty()) {
      profits.push(vps.top().second-vps.top().first);
      vps.pop();
    }
    for (int i = 0; i < k && !profits.empty(); i++) {
      res += profits.top();
      profits.pop();
    }
    return res;
  }
};

//MaskRay's Solution
class Solution {
public:
  int maxProfit(int k, vector<int> &a) {
    int n = (int)a.size();
    stack<pair<int,int>> vp;
    vector<int> g;
    for (int v = 0, p; v < n; v = p+1) {
      for (; v+1 < n && a[v] >= a[v+1]; v++); // local minimum (valley)
      for (p = v+1; p+1 < n && a[p] <= a[p+1]; p++); // local maximum (peak)
      if (p >= n) break;
      // exclude 2-3...1-4 and 2-4...1-3
      for (; ! vp.empty() && a[vp.top().first] >= a[v]; vp.pop())
        g.push_back(a[vp.top().second]-a[vp.top().first]);
      // 1-2...3-4 => 1-4 + 2-3 | 1-3...2-4 => 1-4 + 3-2
      for (; ! vp.empty() && a[vp.top().second] <= a[p]; vp.pop()) {
        int x = a[vp.top().second]-a[v];
        if (x > 0)
          g.push_back(x);
        v = vp.top().first;
      }
      vp.push(make_pair(v, p));
    }
    for (; ! vp.empty(); vp.pop())
      g.push_back(a[vp.top().second]-a[vp.top().first]);
    k = min(k, (int)g.size());
    if (k > 0)
      nth_element(g.begin(), g.begin()+k-1, g.end(), greater<int>()); // nth \in [first,last] in C++14, \in [first,last) in C++11
    return accumulate(g.begin(), g.begin()+k, 0);
  }
};
