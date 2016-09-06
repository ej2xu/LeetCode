class Solution {
public:
    int compareVersion(string v1, string v2) {
      int i = 0, j = 0;
      int num1 = 0, num2 = 0;
      while (i<v1.size() || j<v2.size()) {
        while (i < v1.size() && v1[i]!='.') {
          num1 = 10*num1 + (v1[i++]-'0');
        }
        while (j < v2.size() && v2[j]!='.') {
          num2 = 10*num2 + (v2[j++]-'0');
        }
        if (num1 > num2) return 1;
        if (num1 < num2) return -1;
        num1=0;
        num2=0;
        i++;
        j++;
      }
      return 0;
    }
};
