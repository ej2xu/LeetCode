class Solution {
public:
  string addStrings(string n1, string n2) {
    int i = n1.size()-1, j = n2.size()-1, len = max(i,j) + 2, k = len - 1, carry = 0;
    string sum(len, '0');
    while (i >= 0 || j >= 0) {
      int digit = carry + (i>=0 ? (n1[i--]-'0') : 0) + (j>=0?  (n2[j--]-'0') : 0);
      sum[k--] += digit % 10;
      carry = digit / 10;
    }
    if (carry) {
      sum[0] += carry;
      return sum;
    }
    else
      return sum.substr(1);
  }
};
