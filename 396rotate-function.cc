class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
      int ma = 0, sum = 0, len = A.size();
      for (int i = 0; i < len; i++) {
        ma += i * A[i];
        sum += A[i];
      }
      int cur = ma;
      for (int i = len-1; i > 0; i--) {
        cur += sum - len * A[i];
        ma = max(ma, cur);
      }
      return ma;
    }
};
