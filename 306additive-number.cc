class Solution {
public:
  bool isAdditiveNumber(string num) {
    for (int i = 1; i <= num.size()/2; i++)
      for (int j = 1; j <= (num.size()-i)/2; j++)
        if (check(num.substr(0, i), num.substr(i, j), num.substr(i+j)))
          return true;
    return false;
  }
private:
  bool check(string n1, string n2, string n) {
    if (n1.size() > 1 && n1[0] == '0' || n2.size() > 1 && n2[0] == '0')
      return false;
    string sum = add(n1, n2);
    if (sum == n)
      return true;
    if (sum.size() >= n.size() || sum.compare(n.substr(0, sum.size())))
      return false;
    return check(n2, sum, n.substr(sum.size()));
  }
  string add(string n1, string n2) {
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
