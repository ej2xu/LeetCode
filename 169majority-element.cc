class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int x, c = 0;
      for (auto n: nums) {
        if (!c) {
          x = n;
          c++;
        }
        else if (x == n)
          c++;
        else
          c--;
      }
      return x;
    }
};
