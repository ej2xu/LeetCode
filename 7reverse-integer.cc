class Solution {
public:
    int reverse(int x) {
      int res = 0, tail, tmpres;
      while (x) {
        tail = x%10;
        tmpres = res*10 + tail;
        if ((tmpres-tail)/10 != res)
          return 0;
        res = tmpres;
        x /= 10;
      }
      return res;
    }
};
