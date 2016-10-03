class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int b = INT_MIN, s = 0;
    for (int p : prices) {
      b = max(b, s-p);
      s = max(s, b+p);
    }
    return s;
  }
};

//peak valley
class Solution {
public:
  int maxProfit(vector<int>& prices) {
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

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int profit = 0;
    for(int i = 1; i < prices.size(); i++)
      if (prices[i] > prices[i-1])
        profit += prices[i] - prices[i-1];
    return profit;
  }
};
