class Solution {
public:
  string multiply(string num1, string num2) {
    int m = num1.size();
    int n = num2.size();
    string res(m+n, '0');
    for (int i = m-1; i >= 0; i--) {
      int carry = 0;
      for (int j = n-1; j >= 0; j--) {
        int digit = (num1[i]-'0')*(num2[j]-'0') + res[i+j+1] - '0' + carry;
        res[i+j+1] = digit % 10 + '0';
        carry = digit / 10;
      }
      res[i] = carry + '0';
    }
    return res.erase(0, min(res.find_first_not_of('0'), res.size()-1));
  }
};
