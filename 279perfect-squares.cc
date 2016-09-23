class Solution {
public:
  int numSquares(int n) {
    while((n & 3) == 0)
      n >>= 2;
    if ((n & 7) == 7)
      return 4; // Legendre's three-square thm: n can be represented as sum of three squares iff n not in the form 4^a(8b+7)
    int a = 1, b = sqrt(n);
    if (!(n -= b*b))
      return 1;
    b += b - 1;
    while (a-2 <= b)
      if (n > 0) {
        n -= a;
        a += 2;
      }
      else if (n < 0) {
        n += b;
        b -= 2;
      }
      else
        return 2;
    return 3;
  }
};

//BFS
class Solution {
public:
  int numSquares(int n) {
    if (!n) return 0;
    vector<int> sqs;
    vector<int> cnt(n);
    for (int i = 1, j; (j = i*i) <= n; i++) {
      sqs.push_back(j);
      cnt[j-1] = 1;
    }
    if (cnt.back()) return 1;
    queue<int> searchq;
    for (int sq: sqs)
      searchq.push(sq);
    int count = 1;
    while (!searchq.empty()) {
      count++;
      int searchqsize = searchq.size();
      for (int i = 0; i < searchqsize; i++) {
        int cur = searchq.front();
        searchq.pop();
        for (int sq: sqs) {
          int tmp = cur + sq;
          if (tmp > n)
            break;
          else if (tmp == n)
            return count;
          else if (!cnt[tmp-1]) {
            cnt[tmp-1] = count;
            searchq.push(tmp);
          }
        }
      }
    }
    return 0;
  }
};

int numSquares(int n) {
    static vector<int> dp {0};
    int m = dp.size();
    dp.resize(max(m, n+1), INT_MAX);
    for (int i=1, i2; (i2 = i*i)<=n; ++i)
        for (int j=max(m, i2); j<=n; ++j)
            if (dp[j] > dp[j-i2] + 1)
                dp[j] = dp[j-i2] + 1;
    return dp[n];
}
