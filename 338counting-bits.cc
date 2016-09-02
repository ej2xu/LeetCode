class Solution {
public:
    vector<int> countBits(int num) {
      vector<int> r(num+1,0);
      for (int i = 1; i <= num; i++)
        r[i] = r[i&(i-1)]+1;
      return r;
    }
};

//solution using range
class Solution {
public:
    vector<int> countBits(int num) {
      vector<int> r(num+1,0);
      int pow = 1;
      for (int i = 1, t =0; i <= num; i++, t++) {
        if (pow = i) {
          pow *= 2;
          t = 0;
        }
        r[i] = r[t] + 1;
      }
      return r;
    }
};
