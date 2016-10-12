class Solution {
public:
  int minimumTotal(vector<vector<int>>& t) {
    for (int i = 1; i < t.size(); i++) {
      t[i][0] += t[i-1][0];
      t[i][i] += t[i-1][i-1];
      for (int j = 1; j < i; j++)
        t[i][j] += min(t[i-1][j-1], t[i-1][j]);
    }
    return *min_element(t.back().begin(), t.back().end());
  }
};

class Solution {
public:
  int minimumTotal(vector<vector<int>>& t) {
    vector<int> dp(t.size(), 0);
    dp[0] = t[0][0];
    for (int i = 1; i < t.size(); i++) {
      dp[i] = dp[i-1]+t[i][i];
      for (int j = i-1; j >= 1; j--)
        dp[j] = min(dp[j], dp[j-1]) + t[i][j];
      dp[0] += t[i][0];
    }
    return *min_element(dp.begin(), dp.end());
  }
};

int minimumTotal(vector<vector<int> > &triangle) {
  int n= triangle.size();
  for(int i=n-2; i>=0; i--)
    for(vector<int>::size_type j=0; j<=i; j++)
      triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
  return triangle[0][0];
}

int minimumTotal(vector<vector<int> > &triangle) {
    int n = triangle.size();
    vector<int> minlen(triangle.back());
    for (int layer = n-2; layer >= 0; layer--) // For each layer
    {
        for (int i = 0; i <= layer; i++) // Check its every 'node'
        {
            // Find the lesser of its two children, and sum the current value in the triangle with it.
            minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i];
        }
    }
    return minlen[0];
}
