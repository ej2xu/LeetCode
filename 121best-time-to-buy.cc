class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int maxprofit = 0, minprice = INT_MAX;
      for (auto p: prices) {
        if (p < minprice)
          minprice = p;
        else if (p-minprice > maxprofit)
          maxprofit = p - minprice;
      }
      return maxprofit;
    }
};

//alternative Solution
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int b = INT_MIN, s = 0;
    for (int p : prices) {
      b = max(b, -p);
      s = max(s, b+p);
    }
    return s;
  }
};

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        int maxProfit = 0, minPrice = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i - 1]) {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            } else {
                 minPrice = min(minPrice, prices[i]);
            }
        }
        return maxProfit;
    }
};
